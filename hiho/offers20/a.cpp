#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a[1111];
int fa[1111];
int n, k;
bool v[1111];

void dfs(int x) {
    v[x] = true;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (!v[y]) {
            fa[y] = x;
            dfs(y);
        }

    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(k);
    for (int i = 1; i <= n; ++i) {
        printf("%d", fa[i]);
        printf(i == n ? "\n" : " ");
    }
    return 0;
}