#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>

using namespace std;


const int MOD = 1000000007;

int n, m, f[611][311][311];

void work() {
    scanf("%d%d", &n, &m);
    n <<= 1;
    f[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= min(n>>1, i); ++j) {
            for (int k = 0; k <= min(n>>1, i); ++k) {
                if (f[i][j][k] == 0) continue;
                if (k == 0) {
                    f[i+1][j+1][0] += f[i][j][k];
                    f[i+1][j+1][0] %= MOD;
                } else {
                    f[i+1][j][k-1] += f[i][j][k];
                    f[i+1][j][k-1] %= MOD;
                }
                f[i+1][j][k+1] += f[i][j][k];
                f[i+1][j][k+1] %= MOD;
            }
        }
    }
    printf("%d\n", f[n][m][m]);


}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}