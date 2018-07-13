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

int n, f[411][211][211], a[211][211];

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < n*2; ++i) {
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= n; ++y) {
                if (i - x < 0 || i - y < 0) continue;
                for (int dx = 0; dx < 2; ++dx) {
                    for (int dy = 0; dy < 2; ++dy) {
                        f[i][x][y] = max(f[i][x][y], f[i-1][x-dx][y-dy]);
                    }
                }
                f[i][x][y] += a[x][i-x+1];
                if (y != x) f[i][x][y] += a[y][i-y+1];
                //printf("%d %d %d %d\n", i, x, y, f[i][x][y]);
            }
        }
    }
    printf("%d\n", f[n*2-1][n][n] + a[1][1] + a[n][n]);

}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}