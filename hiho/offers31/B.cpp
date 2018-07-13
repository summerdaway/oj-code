#include <map>
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

int n, m, K, dist[311][311], f[5000][15], X[20], Y[20], d[20][20], S;
char a[311][311];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int> > q;

void bfs(int sx, int sy) {

    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 0;
    while (!q.empty()) q.pop();
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        int x = now.first, y = now.second;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || a[xx][yy] == '1') continue;
            if (dist[xx][yy] == -1) {
                dist[xx][yy] = dist[x][y] + 1;
                q.push(make_pair(xx, yy));
            }
        }
    }
}

void work() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < K; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        X[i] = x, Y[i] = y;
    }
    X[K] = 0, Y[K++] = 0;
    X[K] = n-1, Y[K++] = m-1;
    for (int i = 0; i < K; ++i) {
        bfs(X[i], Y[i]);
        for (int j = 0; j < K; ++j) {
            d[i][j] = dist[X[j]][Y[j]];
        }
    }

    S = (1 << K);
    memset(f, -1, sizeof(f));
    f[0][K-2] = 0;
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < K; ++j) {
            if (f[i][j] == -1) continue;
            for (int k = 0; k < K; ++k) {
                int s = i | (1 << k);
                if (d[j][k] != -1 && (f[s][k] == -1 || f[s][k] > f[i][j] + d[j][k])) {
                    f[s][k] = f[i][j] + d[j][k];
                }

            }
        }
    }
    printf("%d\n", f[S-1][K-1]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
