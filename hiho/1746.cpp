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

int n, m, q, f[101111][20], s[101111], t[101111], g[101111], h[101111];
vector<int> a[101111];



void dfs(int x, int ht) {
    s[x] = ++m;
    h[x] = ht;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        dfs(y, ht+1);
        g[x] += g[y];
    }
    t[x] = ++m;
    g[x] += 1;
}

int lca_fake(int x, int y) {
    if (s[x] < s[y] && t[y] < t[x]) {
        return x;
    }
    if (s[y] < s[x] && t[x] < t[y]) {
        return y;
    }
    return -1;
}

long long calc(int x, int y) {
    int dh = h[y] - h[x] - 1;
    int z = y;
    for (int i = 0; i < 18; ++i) {
        if ((dh >> i) & 1) {
            z = f[z][i];
        }
    }
    return 1LL*(n-g[z])*g[y];
}

void work() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        f[y][0] = x;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!f[i][0]) {
            dfs(i, 0);
        }
    }
    for (int i = 0; i < 18; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[j][i+1] = f[f[j][i]][i];
        }
    }
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y) {
            printf("%lld\n", 1LL*(n-g[x]+1)*g[x]);
        } else {
            int z = lca_fake(x, y);
            if (z == x) {
                printf("%lld\n", calc(x, y));
            } else if (z == y) {
                printf("%lld\n", calc(y, x));
            } else {
                printf("%lld\n", 1LL * g[x] * g[y]);
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