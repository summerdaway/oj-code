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

long long A[2][2], B[2][2], C[2][2], n;
const long long MOD = 1000000007;

void fast_mod(long long x) {
    if (x == 0) {
        memset(B, 0, sizeof(B));
        B[0][0] = B[1][1] = 1;
        return;
    }
    fast_mod(x >> 1);
    memset(C, 0, sizeof(C));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C[i][j] += B[i][k]*B[k][j] % MOD;
                C[i][j] %= MOD;
            }
        }
    }
    memcpy(B, C, sizeof(C));
    if (x & 1) {
        memset(C, 0, sizeof(C));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    C[i][j] += B[i][k] * A[k][j] % MOD;
                    C[i][j] %= MOD;
                }
            }
        }
        memcpy(B, C, sizeof(C));
    }
    return;
}

void work() {
    A[0][0] = A[0][1] = A[1][0] = 1;
    A[1][1] = 2;
    fast_mod(n - 1);
    printf("%lld\n", (B[1][0] + B[1][1]) % MOD);

}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (scanf("%lld", &n) != EOF) {
        work();
    }
    return 0;
}