#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int> > > q;
int dist[51111], n, SS, TT;
vector<int> a[51111], b[51111], c[5001111];
bool v[51111];

int spfa() {
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        int d = now.first, x = now.second;
        if (v[x]) continue;
        if (x == n + 1) break;
        v[x] = true;
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            if (dist[y] == -1 || dist[y] > dist[x] + 1) {
                dist[y] = dist[x] + 1;
                q.push(make_pair(dist[y], y));
            }
        }
        for (int i = 0; i < b[x].size(); ++i) {
            int station = b[x][i];
            for (int j = 0; j < c[station].size(); ++j) {
                int y = c[station][j];
                if (dist[y] == -1 || dist[y] > dist[x] + 1) {
                    dist[y] = dist[x] + 1;
                    q.push(make_pair(dist[y], y));
                }
            }
        }
    }
    if (dist[n+1] == -1) {
        return -1;
    } else {
        return dist[n+1] - 2;
    }
}

void work() {
    scanf("%d%d%d", &n, &SS, &TT);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);

        for (int j = 0; j < x; ++j) {
            int y;
            scanf("%d", &y);
            b[i].push_back(y);
            if (b[i][j] == SS) {
                a[0].push_back(i);
            }
            if (b[i][j] == TT) {
                a[i].push_back(n+1);
            }
            c[b[i][j]].push_back(i);
        }
    }
    printf("%d\n", spfa());
}

int main() {

    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}