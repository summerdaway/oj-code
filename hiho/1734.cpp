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

queue<pair<int, int> > q;
int n, d1[1111][1111], d2[1111][1111];
char a[1111][1111];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    q.push(make_pair(0, 0));
    memset(d1, -1, sizeof(d1));
    d1[0][0] = 0;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        int x = now.first, y = now.second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
            if (d1[xx][yy] == -1) {
                d1[xx][yy] = d1[x][y] + 1;
                if (a[xx][yy] != '#') {
                    q.push(make_pair(xx, yy));
                }
            }
        }
    }
    while (!q.empty()) q.pop();
    q.push(make_pair(n-1, n-1));
    memset(d2, -1, sizeof(d2));
    d2[n-1][n-1] = 0;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        int x = now.first, y = now.second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
            if (d2[xx][yy] == -1) {
                d2[xx][yy] = d2[x][y] + 1;
                if (a[xx][yy] != '#') {
                    q.push(make_pair(xx, yy));
                }
            }
        }
    }

    int ans = d1[n-1][n-1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '#') {
                if (d1[i][j] == -1 || d2[i][j] == -1) continue;
                if (ans == -1 || ans > d1[i][j] + d2[i][j]) {
                    ans = d1[i][j] + d2[i][j];
                }
            }
        }
    }
    printf("%d\n", ans);
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
