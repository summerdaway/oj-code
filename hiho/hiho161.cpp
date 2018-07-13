#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int fa[511];
int n, m;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void work() {
    scanf("%d%d", &n, &m);
    int ans = 1;
    if (m != n - 1) {
        ans = 0;
    }
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = find(x), y = find(y);
        if (x == y) {
            ans = 0;
        }
        fa[x] = y;
    }
    printf(ans ? "YES\n" : "NO\n");
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}