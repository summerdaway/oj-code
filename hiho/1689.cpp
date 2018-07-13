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

int n, m;
pair<int, int> a[1010111];
bool v[1011110], c[1011111];
char c1[100], c2[100], c3[100];
vector<int> b[1011011];

bool dfs(int x, int y) {
    v[x] = true;
    if (x == y) {
        return true;
    }
    for (int i = 0; i < b[x].size(); ++i) {
        if (!v[b[x][i]]) {
            if (dfs(b[x][i], y)) {
                return true;
            }
        }
    }
    return false;
}

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        b[i].clear();
    }
    for (int i = 0; i <= x; ++i) {
        b[a[i].first].push_back(a[i].second);
        if (c[i]) {
            b[a[i].second].push_back(a[i].first);
        }
    }
    memset(v, 0, sizeof(v));
    if (dfs(1, n)) return true;
    memset(v, 0, sizeof(v));
    return dfs(n, 1);
}


void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s%s%s", c1, c2, c3);
        int x = 0, y = 0;
        for (int j = 1; j < strlen(c1); ++j) {
            x *= 10;
            x += c1[j] - '0';
        }
        for (int j = 1; j < strlen(c3); ++j) {
            y *= 10;
            y += c3[j] - '0';
        }

        if (c2[0] == '>') {
            swap(x, y);
        }
        a[i].first = x, a[i].second = y, c[i] = c2[0] == '=';
    }
    int l = -1, r = m;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r < m) {
        printf("%d\n", r + 1);
    } else {
        printf("-1\n");
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