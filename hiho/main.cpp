#prag\
ma GCC optimize ("O4") 
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
const int MOD = 998244353;
int X, N, M;
int n, m, A[1111], B[1111], S[1111], T[130];
long long f[201][128][1001], P[2222], C[2222][2222];

void add(long long &s, long long x) {
    s = (s + x) % MOD;
}

void work() {
    scanf("%d%d%d", &X, &N, &M);
    if (X < 1 || X > 200) while(1);
    if (N < 1 || N > 1000) while(1);
    if (M < 1 || M > 1000) while(1);
    int XX = X;
    for (int i = 0, x; i < N; i ++) {
        scanf("%d", &x);
        if (x > 1000 || x < 1) while(1);
        if (x == 1) continue;
        A[n ++] = x;
        XX /= x;
    }
    for (int i = 0, x; i < M; i ++) {
        scanf("%d", &x);
        B[x] ++;
        if (x > 1000 || x < 1) while(1);
    }
    P[0] = 1;
    for (int i = 1; i <= N+M; i ++) {
        P[i] = P[i-1] * i % MOD;
    }
    if (XX == 0 || B[1] > 0) {
        printf("%lld\n", P[N+M]);
        return;
    }
    if (n > 7) {
        while(1);
    }
    for (int i = 1000; i >= 0; i --) {
        S[i] = B[i] + S[i+1];
    }
    for (int s = 0; s < (1<<n); s ++) {
        T[s] = 1;
        for (int i = 0; i < n; i ++) {
            if ((s >> i) & 1) T[s] *= A[i];
        }
    }
    f[X][(1<<n)-1][0] = 1;
    long long ret = 0;
    for (int x = X; x >= 0; x --) {
        for (int s = 0; s < (1<<n); s ++) {
            for (int i = 0; i <= S[x+1]; i ++) {
                if (f[x][s][i] == 0) continue;
                if (x < T[s]) {
                    int tot = M - i;
                    for (int j = 0; j < n; j ++) {
                        tot += (s >> j) & 1;
                    }
                    add(ret, f[x][s][i]*P[tot]);
                    continue;
                }
                if (i < S[x+1]) {
                    add(f[x][s][i+1], f[x][s][i]*(S[x+1]-i));
                }
                for (int j = 0; j < n; j ++) {
                    if ((s >> j) & 1) {
                        add(f[x/A[j]][s^(1<<j)][i], f[x][s][j]);
                    }
                }
                for (int k = 1; k <= x; k ++) {
                    if (B[k] > 0) add(f[x%k][s][i+1], f[x][s][i]*B[k]);
                }
            }
        }
    }
    for (int i = 0; i <= 2000; i ++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j ++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    ret = ret * C[N+M][n+M] % MOD;
    printf("%lld\n", ret);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = clock();
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
