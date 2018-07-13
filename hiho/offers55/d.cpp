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

long long T[500000][61], a[51111], ans[61], s1[61], s2[61], s11[61], s22[61];
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

void modify(int node, int l, int r, int x, long long y) {
    if (l == r) {
        memset(T[node], 0, sizeof(T[node]));
        for (int i = 0; i <= 60; ++i) {
            if ((y >> i)&1) {
                T[node][i] = y;
                break;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        modify(node<<1, l, mid, x, y);
    } else {
        modify((node<<1)+1, mid+1, r, x, y);
    }
    memset(T[node], 0, sizeof(T[node]));
    merge(T[(node<<1)], T[node]);
    merge(T[(node<<1)+1], T[node]);

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
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            long long y;
            scanf("%d%lld", &x, &y);
            modify(1, 1, n, x, y);
        } else {
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            memset(ans, 0, sizeof(ans));
            query(1, 1, n, l1, r1);
            memcpy(s1, ans, sizeof(ans));

            memset(ans, 0, sizeof(ans));
            query(1, 1, n, l2, r2);
            memcpy(s2, ans, sizeof(ans));

            memcpy(s11, s1, sizeof(s1));
            memcpy(s22, s2, sizeof(s2));
            int x = 0, y = 0;
            for (int i = 0; i <= 60; ++i) {
                if (s2[i]) y++;
            }
            merge(s1, s2);
            for (int i = 0; i <= 60; ++i) {
                if (s2[i]) x++;
            }
            bool f1_2 = false;
            if (x == y) f1_2 = true;

            memcpy(s1, s11, sizeof(s11));
            memcpy(s2, s22, sizeof(s22));
            x = y = 0;
            for (int i = 0; i <= 60; ++i) {
                if (s1[i]) x++;
            }
            merge(s2, s1);
            for (int i = 0; i <= 60; ++i) {
                if (s1[i]) y++;
            }
            bool f2_1 = false;
            if (x == y) f2_1 = true;
            if (f1_2 && f2_1) {
                printf("0\n");
            } else if (f1_2) {
                printf("2\n");
            } else if (f2_1) {
                printf("1\n");
            } else {
                printf("3\n");
            }
        }
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
