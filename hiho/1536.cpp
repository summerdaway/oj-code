#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int n, R;
pair<int, int> a[5111];
int f[5111][5111];

void work() {
    scanf("%d%d", &n, &R);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].first);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].second);
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        f[1][i] = a[1].second;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (f[i][j] == -1) continue;
            if (j + R + 1 <= n) f[i+1][j+R+1] = max(f[i+1][j+R+1], f[i][j] + a[i+1].second);
            if (j > i) {
                f[i+1][j] = max(f[i+1][j], f[i][j]);
            } else if (j == i) {
                f[i+1][j+1] = max(f[i+1][j+1], f[i][j]);
            }
            //printf("%d %d %d\n", i, j, f[i][j]);
        }
    }
    printf("%d\n", f[n][n]);

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}