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


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, a[222][222], f[201][201][201], S[611][611][21], T[611][611][21], c[611][611], tot[30], q, ans[201][201][201],
X[101111], Y[101111], K[101111];
vector<int> d[201][201];
bool v[201][201][201];
struct Node {
    int x, y;
} b[10];

void get_points(int x, int y, int d) {
    for (int i = 0; i < 4; ++i) {
        b[i].x = x + dx[i]*d, b[i].y = y + dy[i]*d;
        //printf("point=%d %d\n", b[i].x, b[i].y);
    }
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            c[i+n][j+n] = a[i][j];
        }
    }

    for (int i = 2; i <= n*6; ++i) {
        int st = 1;
        if (i > 3*n + 1) st = i - 3*n;
        S[st][i-st][c[st][i-st]]++;
        for (int j = st+1; j <= min(i-1, n*3); ++j) {
            memcpy(S[j][i-j], S[j-1][i-(j-1)], sizeof(S[j-1][i-(j-1)]));
            S[j][i-j][c[j][i-j]]++;
        }
    }
    for (int i = 1-3*n; i <= 3*n-1; ++i) {
        int st = 1;
        if (i > 0) st = i + 1;
        T[st][st-i][c[st][st-i]]++;
        for (int j = st+1; j <= min(n*3, i + 3*n); ++j) {
            memcpy(T[j][j-i], T[j-1][j-1-i], sizeof(T[j-1][j-1-i]));
            T[j][j-i][c[j][j-i]]++;
        }
    }

    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        X[i] = x, Y[i] = y, K[i] = k;
        v[x][y][k] = true;
        d[x][y].push_back(k);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (d[i][j].size() == 0) continue;
            int mx = 0;
            for (int k = 0; k < d[i][j].size(); ++k) {
                mx = max(d[i][j][k], mx);
            }
            memset(tot, 0, sizeof(tot));
            tot[a[i][j]] = 1;
            for (int k = 1; k <= max(mx, n); ++k) {
                get_points(i+n, j+n, k);
                tot[c[b[2].x][b[2].y]]--;
                tot[c[b[0].x][b[0].y]]++;
                for (int t = 1; t <= 20; ++t) {
                    tot[t] += S[b[3].x][b[3].y][t] - S[b[0].x][b[0].y][t];
                    tot[t] += S[b[2].x][b[2].y][t] - S[b[1].x][b[1].y][t];
                    tot[t] += T[b[1].x][b[1].y][t] - T[b[0].x][b[0].y][t];
                    tot[t] += T[b[2].x][b[2].y][t] - T[b[3].x][b[3].y][t];
                    if (k % t == 0) {
                        ans[i][j][k] += tot[t];
                    }
                }
                v[i][j][k] = true;
            }

            for (int kk = 0; kk < d[i][j].size(); ++kk) {
                int k = d[i][j][kk];
                if (!v[i][j][k]) {
                    for (int t = 1; t <= 20; ++t) {
                        if (k % t == 0) {
                            ans[i][j][k] += tot[t];
                        }
                    }
                    v[i][j][k] = true;
                }
            }
        }
    }

    for (int i = 1; i <= q; ++i) {
        printf("%d\n", ans[X[i]][Y[i]][K[i]]);
    }
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}