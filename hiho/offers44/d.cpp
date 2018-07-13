#prag\
ma GCC optimize ("O2") 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, m, K, s[311][311], ans, a[311][311], b[611], ct, t[311], T[611];
map<int, int> g;


void add(int x, int y) {
    for (int i = x; i <= ct; i += i&(-i)) {
        T[i] = min(T[i], y);
    }
}

int query(int x) {
    int ret = m;
    for (int i = x; i; i -= i&(-i)) {
        ret = min(ret, T[i]);
    }
    return ret;
}

void work() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    n = m = 300;
    K = 202020;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            s[j][i] = s[j-1][i] + a[j][i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ct = 0;
            g.clear();
            for (int k = 1; k <= m; ++k) {
                t[k] = s[j][k] - s[i-1][k] + t[k-1];
                b[ct++] = -t[k];
                b[ct++] = K - t[k];
            }
            b[ct++] = 0;
            for (int k = 0; k <= ct; ++k) {
                T[k] = ct;
            }

            sort(b, b + ct);
            for (int k = 0; k < ct; ++k) {
                g[b[k]] = k + 1;
                int x = b[k];
                while (k < ct && x == b[k]) {
                    k++;
                }
                k--;
            }
            add(g[-0], 0);
            for (int k = 1; k <= m; ++k) {
                int ret = k - query(g[K - t[k]]);
                ans = max(ans, ret * (j-i+1));
                add(g[-t[k]], k);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}

/*
f[ii] = max_{jj: t[ii] - t[jj] <= K}(ii - jj)
= ii - min_{jj:t[ii]-t[jj]<=K} jj
-t[jj] <= K - t[ii]
*/



