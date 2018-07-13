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

vector<int> a[1111];
int n, m, ans, match[1111], c[1111];
bool v[1111];

void dfs(int x, int color) {
    c[x] = color;
    v[x] = true;
    for (int i = 0; i < a[x].size(); ++i) {
        if (!v[a[x][i]]) dfs(a[x][i], 1-color);
    }
}

bool dfs1(int x) {
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (v[y]) continue;
        v[y] = true;
        if (!match[y] || dfs1(match[y])) {
            match[y] = x;
            match[x] = y;
            return true;
        }
    }
    return false;
}

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) dfs(i, 0);
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] && !match[i]) {
            memset(v, 0, sizeof(v));
            ans += dfs1(i);
        }
    }
    printf("%d\n%d\n", ans, n - ans);
}

int main() {

    freopen("input.txt", "r", stdin);
    int TC = 1;
    // scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
