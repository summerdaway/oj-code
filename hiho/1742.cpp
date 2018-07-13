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

int f[101111], n, fa[101111];
long long g[101111], ans[101111];
vector<int> a[101111];
bool v[101111];

void dfs(int x, int father) {
    v[x] = true;
    fa[x] = father;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (v[y]) {
            continue;
        }
        dfs(y, x);
        g[x] += g[y] + f[y];
        f[x] += f[y];
    }
    f[x] += 1;
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    memset(v, 0, sizeof(v));
    v[x] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < a[now].size(); ++i) {
            int y = a[now][i];
            if (!v[y]) {
                q.push(y);
                v[y] = true;
            }
        }
        if (fa[now] == 0) {
            ans[now] = g[now];
            continue;
        }
        long long tmp = ans[fa[now]];
        ans[now] = tmp + n - f[now] - f[now];
    }
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
    bfs(1);
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", ans[i]);
    }

}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
