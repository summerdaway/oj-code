#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

vector<int> a[101111];
int n, ans;

int dfs(int x, int fa) {
    int tot = 1;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (y == fa) continue;
        tot += dfs(y, x);
    }
    if ((tot & 1) == 0) {
        ans++;
    }
    return tot;
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1, 0);
    printf("%d\n", ans - 1);


}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}