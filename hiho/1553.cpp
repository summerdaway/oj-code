#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

const long long MOD = 1000000007;

int n, q, m, sqrtn;
struct Node {
    int l, r, k, x;
} d[101111];
vector<Node> a;
long long ans[101111], pow1[101111][111];
int ct[101111], A[101111];
set<int> f;
int sum[101111];

bool cmp(const Node &x, const Node &y) {
    if (x.l/sqrtn == y.l/sqrtn) {
        return x.r < y.r;
    }
    return x.l/sqrtn < y.l/sqrtn;
}

void update(int t, int x) {
    //printf("A[i]=%d x=%d\n", t, x);
    sum[ct[t]]--;
    if (ct[t] >= sqrtn && sum[ct[t]] == 0) {
        f.erase(ct[t]);
    }
    ct[t] += x;
    if (ct[t] >= sqrtn && sum[ct[t]] == 0) {
        f.insert(ct[t]);
    }
    sum[ct[t]]++;
}

void calc() {
    m = q;
    sort(a.begin(), a.end(), cmp);
    memset(ct, 0, sizeof(ct));
    memset(sum, 0, sizeof(sum));
    f.clear();

    for (int i = 0; i < m; ++i) {
        if (i == 0) {
            for (int j = a[i].l; j <= a[i].r; ++j) {
                update(A[j], 1);
            }
        } else {
            if (a[i-1].r < a[i].r) {
                for (int j = a[i-1].r + 1; j <= a[i].r; ++j) {
                    update(A[j], 1);
                }
            } else {
                for (int j = a[i].r + 1; j <= a[i-1].r; ++j) {
                    update(A[j], -1);
                }
            }
            if (a[i-1].l < a[i].l) {
                for (int j = a[i-1].l; j < a[i].l; ++j) {
                    update(A[j], -1);
                }
            } else {
                for (int j = a[i].l; j < a[i-1].l; ++j) {
                    update(A[j], 1);
                }
            }
        }
        ans[a[i].x] = 0;
        //printf("sqrtn=%d\n", sqrtn);
        for (int j = 1; j < sqrtn; ++j) {
            //printf("sum=%d\n", sum[j]);
            ans[a[i].x] += pow1[j][a[i].k] * sum[j] % MOD;
            ans[a[i].x] %= MOD;
        }
        for (set<int>::iterator iter = f.begin(); iter != f.end(); ++iter) {
            ans[a[i].x] += pow1[*iter][a[i].k] * sum[*iter] % MOD;
            ans[a[i].x] %= MOD;
        }
    }

}

void work() {
    scanf("%d%d", &n, &q);
    sqrtn = (int) sqrt(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &d[i].l, &d[i].r, &d[i].k);
        d[i].x = i;
    }
    a.clear();
    for (int j = 0; j < q; ++j) {
        a.push_back(d[j]);
    }
    calc();

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }

}

int main() {

    for (int i = 1; i <= 100000; ++i) {
        pow1[i][0] = 1;
        for (int j = 1; j <= 100; ++j) {
            pow1[i][j] = pow1[i][j-1] * i % MOD;
        }
    }

    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}