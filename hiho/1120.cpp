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

pair<int, int> b[20];
int p, n, m, N, a[20][20], c[20][20], ans[20][2], ans1, ans2;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


bool check() {
    for (int i = 0; i < p; ++i) {
        int x = b[i].first, y = b[i].second;
        if (!c[x][y]) continue;
        for (int j = 0; j < 8; ++j) {
            int xx = x + dx[j], yy = y + dy[j];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != -1) {
                c[xx][yy]--;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         printf("%d ", c[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != -1 && c[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}


void work() {
    scanf("%d%d", &n, &m);
    p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1) {
                b[p].first = i, b[p].second = j, p++;
            }
        }
    }
    N = 1 << p;
    memset(ans, 0, sizeof(ans));
    ans1 = ans2 = 0;
    for (int i = 0; i < N; ++i) {
        memcpy(c, a, sizeof(c));
        for (int j = 0; j < p; ++j) {
            c[b[j].first][b[j].second] = (i>>j) & 1;
        }
        if (check()) {
            for (int j = 0; j < p; ++j) {
                ans[j][(i>>j)&1] = 1;
            }
        }
    }
    for (int j = 0; j < p; ++j) {
        if (ans[j][0] && ans[j][1]) continue;
        if (ans[j][0]) ans1++;
        if (ans[j][1]) ans2++;
    }
    printf("%d %d\n", ans2, ans1);
}

int main() {

    freopen("input.txt", "r", stdin);
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
