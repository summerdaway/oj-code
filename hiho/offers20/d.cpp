#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 101111

int fa[maxn], n, sg[maxn];
vector<int> a[maxn];

void dfs(int x) {
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        dfs(y);
        sg[x] ^= sg[y] + 1;
    }
}

void work() {
    memset(fa, 0, sizeof(fa));
    memset(sg, 0, sizeof(sg));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        a[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        fa[y] = x;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (fa[i] == 0) {
            dfs(i);
            int ans = 0;
            for (int j = 0; j < a[i].size(); ++j) {
                ans ^= sg[a[i][j]];
            }
            printf("%d%d", sg[i] > 0, ans > 0);
            return;
        }
    }


}


int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
    printf("\n");
    return 0;
}