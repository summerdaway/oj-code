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

int n, w[101111], ans;
vector<int> a[101111];
map<int, int> s[101111];


void dfs(int x, int fa) {
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (y != fa) {
            dfs(y, x);
            int d = w[y] - w[x], t = s[y][d];
            ans = max(ans, s[x][-d] + t + 2);
            s[x][d] = max(s[x][d], t + 1);
        }
    }
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ans = 1;
    dfs(1, 0);
    printf("%d\n", ans);

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