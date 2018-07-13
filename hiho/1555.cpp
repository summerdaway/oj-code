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

long long n, A[4][4], B[4][4], C[4][4], f[4], a, b, c, d;
const long long MOD = 1000000007;

void fast_mod(long long x) {
    if (x == 0) {
        memset(B, 0, sizeof(B));
        for (int i = 0; i < 4; ++i) {
            B[i][i] = 1;
        }
        return;
    }
    fast_mod(x >> 1);
    memset(C, 0, sizeof(C));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                C[i][j] += B[i][k] * B[k][j] % MOD;
                C[i][j] %= MOD;
            }
        }
    }
    if (x & 1) {
        memset(B, 0, sizeof(B));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    B[i][j] += C[i][k] * A[k][j] % MOD;
                    B[i][j] %= MOD;
                }
            }
        }
    } else {
        memcpy(B, C, sizeof(C));
    }
}

void work() {
    scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
    f[0] = 4, f[1] = -a, f[2] = (a*a%MOD-b*2) %MOD, f[3] = (-a*a%MOD*a%MOD + a*b%MOD*3%MOD - c*3%MOD) %MOD;
    //printf("f[3]=%lld\n", f[3]);
    if (n < 4) {
        printf("%lld\n", f[n]);
        return;
    }

    A[0][0] = -a, A[0][1] = -b, A[0][2] = -c, A[0][3] = -d;
    A[1][0] = 1, A[2][1] = 1, A[3][2] = 1;

    fast_mod(n-3);
    long long ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans += B[0][i]*f[3-i] % MOD;
        //printf("%lld ", B[0][i]);
        ans %= MOD;
    }
    ans += MOD;
    printf("%lld\n", ans % MOD);
}


int main() {
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}