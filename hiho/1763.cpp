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

const long long MAXLL = 1LL << 60;
bool vx[201111], vy[201111];
int n, nx, ny;
vector<int> a[201111], w[201111];
long long f[201111], g[201111], h[201111];

void dfs(int x, int fa) {
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (y == fa) continue;
        dfs(y, x);
        f[x] += min(f[y], min(g[y]+w[x][i], h[y]));
        g[x] += min(f[y]+w[x][i], min(g[y], h[y]));
        h[x] += min(f[y]+w[x][i], min(g[y]+w[x][i], h[y]));
    }
    if (vx[x]) {
        g[x] = h[x] = MAXLL;
    }
    if (vy[x]) {
        f[x] = h[x] = MAXLL;
    }
}


void work() {
    scanf("%d", &n);
    scanf("%d", &nx);
    for (int i = 0; i < nx; ++i) {
        int x;
        scanf("%d", &x);
        vx[x] = true;
    }
    scanf("%d", &ny);
    for (int i = 0; i < ny; ++i) {
        int x;
        scanf("%d", &x);
        vy[x] = true;
    }
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x].push_back(y);
        a[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    dfs(1, 0);
    printf("%lld\n", min(f[1], min(g[1], h[1])));
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}