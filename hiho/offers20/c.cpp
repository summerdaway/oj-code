#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int N, M, T, K1, K2, n;
bool v[2001111];
int f[2001111], g[2001111], a[1001111], b[1001111];

int main() {
    scanf("%d%d%d%d%d", &N, &M, &T, &K1, &K2);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        for (int j = (a[i] << 1) + 1; j < (b[i] <<1); ++j) {
            v[j] = true;
        }
    }
    n = T << 1;
    int t = n, e = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i & 1) {
            if (v[i]) e += K1;
            else e += K2;
            continue;
        }
        while (e > M || v[t]) {
            if (v[t-1]) e -= K1;
            else e -= K2;
            t -=2;
        }
        if (i >= t) {
            printf("-1\n");
            return 0;
        }
        if (!v[i]) {
            f[i] = f[t] + 1;
            if (t == n) {
                g[i] = M - e;
            } else {
                g[i] = g[t];
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        if (i & 1) continue;
        printf("%d %d %d\n", i >>1, f[i], g[i]);
    }
    */

    int ans = -1;
    e = 0;
    for (int i = 0; i <= (M << 1) && i < n; ++i) {
        if (i & 1) {
            if (v[i]) e += K1;
            else e += K2;
            continue;
        }
        if (v[i]) continue;
        if (g[i] >= e) {
            if (ans == -1 || ans > f[i]) ans = f[i];
        }


    }
    printf("%d\n", ans);

    return 0;
}