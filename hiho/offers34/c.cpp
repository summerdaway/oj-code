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

double f[2111][2111], a[2111];
int n, m;

double calc(int L, int R) {
    double A, B, C;
    B = C = 0;
    A = R - L + 1;
    for (int i = L; i <= R; ++i) {
        B += -a[i]*2;
        C += a[i]*a[i];
    }
    double x = -B/A/2;
    return A*x*x + B*x + C;
}

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            f[i][j] = 1e30;
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = i; k >= 1; --k) {
                f[i][j] = min(f[i][j], f[k-1][j-1] + calc(k, i));
            }
        }
    }
    printf("%.3lf\n", f[n][min(m, n)]);
}

int main() {

    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}