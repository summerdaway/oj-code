#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int deg[5111], n, m, p, e[5111][5111];
bool v[5111][5111];


void dfs(int x, int t) {
    for (int y = 1; y <= n; ++y) {
        if (e[x][y]) {
            e[x][y]--, e[y][x]--;
            dfs(y, 1);
        }
    }
    printf("%d", x);
    if (t) printf(" ");
    else printf("\n");
}

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x][y]++, e[y][x]++;
        deg[x]++, deg[y]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] & 1) {
            dfs(i, 0);
            return;
        }
    }
    dfs(1, 0);


}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
