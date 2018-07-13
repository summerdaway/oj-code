#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int sequence[300][10], f[101111][300], A[101111][10], a[10];
int n, m;
bool v[5];

void print(int x) {
    for (int i = 0; i < 4; ++i) {
        printf("%d", (x >> (i<<1)) & 3);
    }
}
bool check(int x) {
    memset(v, 0, sizeof(v));
    for (int i = 0; i < 4; ++i) {
        int y = (x >> (i << 1)) & 3;
        if (v[y]) return false;
        v[y] = true;
    }
    return true;
}

void calc_seq() {
    for (int i = 0; i < m; ++i) {

        for (int j = 0; j <= 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                a[k] = (i >> (k << 1)) & 3;
                if (j <= a[k]) a[k]++;
            }
            a[4] = j;
            for (int k = 1; k <= 4; ++k) {
                if (a[k] > a[0]) a[k]--;
                sequence[i][j] |= a[k] << ((k-1) << 1);
            }
        }
    }
}



void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 4; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    if (n == 1) {
        printf("%d\n", A[0][0]);
        return;
    }
    if (n == 2) {
        printf("%d\n", min(A[0][1] + A[1][0], A[0][0] + A[1][1]));
        return;
    }
    if (n == 3) {
        int ans = 2000000000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i != j && i != k && j != k) {
                        ans = min(ans, A[0][i] + A[1][j] + A[2][k]);
                    }
                }
            }
        }
        printf("%d\n", ans);
        return;
    }

    memset(f, -1, sizeof(f));

    for (int i = 0; i < m; ++i) {
        if (!check(i)) continue;
        int x = i & 3;
        if (x > ((i >> 6) & 3)) x--;
        f[0][i] = A[0][x] + A[1][(i>>2) & 3];
    }
    for (int i = 0; i < n - 4; ++i) {
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == -1) continue;
            int y = (j >> 4) & 3; // i + 2

            for (int k = 0; k <= 4; ++k) {
                int upd = A[i+2][y + (y >= k)] + f[i][j];
                int seq = sequence[j][k];
                if (f[i+1][seq] == -1) {
                    f[i+1][seq] = upd;
                } else {
                    f[i+1][seq] = min(f[i+1][seq], upd);
                }
            }
        }
    }

    int ans = 2000000000;
    for (int i = 0; i < m; ++i) {
        if (f[n-4][i] == -1) continue;
        int x = (i >> 4) & 3;
        int y = (i >> 6) & 3;
        if (y > (i & 3)) --y;
        ans = min(ans, f[n-4][i] + A[n-2][x] + A[n-1][y]);
    }


    printf("%d\n", ans);
}

int main() {
    m = 1 << 8;
    calc_seq();
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}