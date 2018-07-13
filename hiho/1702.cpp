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

long long g[111][111][50], f[111][111][50];
int n, a[111][111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 30; ++k) {
                f[i][j][k] = g[i][j][k] = 1000000000;
            }
        }
    }
    f[0][0][0] = g[0][0][0] = a[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 30; ++k) {
                if (j < n - 1) {
                    f[i][j+1][k] = min(f[i][j+1][k], f[i][j][k] + a[i][j+1]);
                    f[i][j+1][k+1] = min(f[i][j+1][k+1], g[i][j][k] + (1<<k) + a[i][j+1]);
                }

                if (i < n - 1) {
                    g[i+1][j][k] = min(g[i+1][j][k], g[i][j][k] + a[i+1][j]);
                    g[i+1][j][k+1] = min(g[i+1][j][k+1], f[i][j][k] + (1<<k) + a[i+1][j]);
                }
            }
        }
    }

    long long ans = f[n-1][n-1][0];
    for (int k = 0; k < 30; ++k) {
        ans = min(ans, f[n-1][n-1][k]);
        ans = min(ans, g[n-1][n-1][k]);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
}