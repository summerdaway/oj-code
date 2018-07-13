#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

long long S1, S2, S3, S, T, ans;
map<long long, long long> f;
int a[101111], n;

void work() {
    scanf("%d", &n);
    T = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        T += a[i];
        if (i && i < n - 1) {
            f[T] += 1;
        }
    }

    ans = 0;
    S1 = 0;
    for (int i = 0; i < n - 2; ++i) {
        S1 += a[i];
        if (i) {
            f[S1]--;
        }
        for (int diff = -1; diff <= 1; ++diff) {
            S2 = S1 + diff;
            S = S1 + S2;
            S3 = T - S;
            if (abs(S3 - S1) <= 1 && abs(S3 - S2) <= 1) {
                ans += f[S];
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}