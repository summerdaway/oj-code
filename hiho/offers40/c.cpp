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

int n, m, f[1111][1111], ans;
char a[1111][1111];

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f[i][j] = 1;
            if (i && j) {
                if (a[i][j] == '0' && a[i-1][j] == '1' && a[i][j-1] == '1' && a[i-1][j-1] == '0') {
                    f[i][j] = max(min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1, f[i][j]);
                }
                if (a[i][j] == '1' && a[i-1][j] == '0' && a[i][j-1] == '0' && a[i-1][j-1] == '1') {
                    f[i][j] = max(min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1, f[i][j]);
                } 
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}