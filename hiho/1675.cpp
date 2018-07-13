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

int n, p, q, ans[2111][2111], a[2111][2111];

void work() {
    scanf("%d%d%d", &n, &p, &q);
    for (int i = 0; i < p; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = z;
    }
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        for (int j = 1; j <= n; ++j) {
            ans[j][y] += a[j][x] * z;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ans[i][j]) {
                printf("%d %d %d\n", i, j, ans[i][j]);
            }
        }
    }
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}