#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;


priority_queue<pair<int, pair<int, int> > > q;
int dist[1010][1010];
int n, m;
bool v[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void work() {
    scanf("%d%d", &n, &m);
    memset(dist, 0, sizeof(dist));
    while (!q.empty()) q.pop();
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        q.push(make_pair(z, make_pair(x, y)));
        dist[x][y] = z;
    }
    while (!q.empty()) {
        pair<int, pair<int, int> > now = q.top();
        q.pop();
        int z = now.first, x = now.second.first, y = now.second.second;
        if (v[x][y]) continue;
        v[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n) {
                continue;
            }
            if (dist[xx][yy] < dist[x][y] - 1) {
                dist[xx][yy] = dist[x][y] - 1;
                q.push(make_pair(dist[xx][yy], make_pair(xx, yy)));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", dist[i][j]);
            printf(j == n - 1 ? "\n" : " ");
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int Test = 1;
    //scanf("%d", &Test);
    while (Test--) {
        work();
    }
    return 0;
}

/*
Problem >_{
    n*n的矩阵，在其中K个格子滴上墨水，墨水有颜色深度，以哈密尔顿距离每次递减1向外扩散，求每个格子最后的颜色。
    $1\le n\le 1000$
    $1\le k\le 10000$
}_<

Solution >_{
    可以看成有一个巨大的源点，到每个滴了墨水的格子的距离是负的墨水深度，相邻格子距离是1，求源点到所有点的最短路
    
    注意
    1. spfa会超时，因为如果有相邻格子深度相差1，深度较小的格子扩散的会被后来更深的深度覆盖，导致多次更新
    2. 可以排序以后做spfa，先做深度深的墨水，可以避免1的问题
    3. 但是无论如何，spfa没有复杂度保证
    4. 以后都用堆优化的dijkstra
}_<
*/