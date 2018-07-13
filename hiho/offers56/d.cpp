#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long T[500000][61], a[51111], ans[61], b[80], s[61];
int n, q;

void merge(long long s1[], long long s2[]) {
    for (int i = 0; i <= 60; ++i) {
        if (s1[i]) {
            long long x = s1[i];
            for (int j = 0; j <= 60; ++j) {
                if ((x >> j) & 1) {
                    x ^= s2[j];
                }
            }
            if (x) {
                for (int j = 0; j <= 60; ++j) {
                    if (((x >> j) & 1) && !s2[j]) {
                        s2[j] = x;
                        break;
                    }
                }
            }
        }
    }
}

void build_tree(int node, int l, int r) {
    if (l == r) {
        for (int i = 0; i <= 60; ++i) {
            if ((a[l] >> i) & 1) {
                T[node][i] = a[l];
                break;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(node<<1, l, mid);
    build_tree((node<<1)+1, mid+1, r);
    merge(T[(node<<1)], T[node]);
    merge(T[(node<<1)+1], T[node]);
}

void query(int node, int l, int r, int x, int y) {
    if (x > r || y < l) {
        return;
    }
    if (x <= l && r <= y) {
        merge(T[node], ans);
        return;
    }
    int mid = (l + r) >> 1;
    query(node<<1, l, mid, x, y);
    query((node<<1)+1, mid+1, r, x, y);
}

void work() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    build_tree(1, 1, n);

    long long s[61];
    memset(s, 0, sizeof(s));
    // return;

    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        memset(ans, 0, sizeof(ans));
        query(1, 1, n, l, r);
        int t;
        scanf("%d", &t);
        memset(s, 0, sizeof(s));
        int ct = 0;
        for (int i = 0; i < t; ++i) {
            long long x;
            scanf("%lld", &x);
            for (int j = 0; j < 61; ++j) {
                if ((x >> j) & 1) {
                    if (s[j]) {
                        x ^= s[j];
                    }
                }
            }
            if (x) {
                ct += 1;
                for (int j = 0; j < 61; ++j) {
                    if (((x>>j)&1) && !s[j]) {
                        s[j] = x;
                        break;
                    }
                }
            }
        }
        int p = 0;
        for (int i = 0; i < 61; ++i) {
            if (ans[i]) {
                long long x = ans[i];
                for (int j = 0; j < 61; ++j) {
                    if ((x>>j)&1) {
                        x ^= s[j];
                    }
                }
                if (x) p++;
            }
        }
        merge(s, ans);
        int ct1 = 0;
        for (int i = 0; i < 61; ++i) {
            if (ans[i]) {
                ct1 += 1;
            }
        }
        printf("%lld\n", 1LL<<(ct1-ct));
    }


}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
