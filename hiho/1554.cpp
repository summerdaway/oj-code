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

char ch[3111], a[111], b[111];
int l1, l2, n, ans, f[3111][111][111], nxt[3111][200];

void work() {
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", ch);
    l1 = strlen(a), l2 = strlen(b), n = strlen(ch);

    memset(nxt, -1, sizeof(nxt));

    for (int i = n - 2; i >= 0; --i) {
        memcpy(nxt[i], nxt[i+1], sizeof(nxt[i+1]));
        nxt[i][ch[i+1]] = i + 1;
    }

    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; ++i) {

        f[i][0][0] = i;
        if (ch[i] == a[0]) {
            f[i][1][0] = i;
        }
        if (ch[i] == b[0]) {
            f[i][0][1] = i;
        }
    }



    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j <= l2; ++j) {
            for (int k = 0; k < n; ++k) {
                if (f[k][i][j] == -1) continue;
                //printf("%d %d %d %d\n", i, j, k, f[k][i][j]);
                if (i < l1 && nxt[k][a[i]] != -1) {
                    //printf("%d\n", nxt[k][a[i]]);
                    f[nxt[k][a[i]]][i+1][j] = max(f[nxt[k][a[i]]][i+1][j], f[k][i][j]);
                }
                if (j < l2 && nxt[k][b[j]] != -1) {
                    //printf("%d\n", nxt[k][b[j]]);
                    f[nxt[k][b[j]]][i][j+1] = max(f[nxt[k][b[j]]][i][j+1], f[k][i][j]);
                }
            }
        }
    }

    ans = n + 1;
    for (int i = 0; i < n; ++i) {
        if (f[i][l1][l2] != -1) {
            ans = min(ans, i - f[i][l1][l2] + 1);
        }
    }
    printf("%d\n", ans == n + 1 ? -1 : ans);
}


int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}