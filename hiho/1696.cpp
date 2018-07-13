#include <map>
#include <set>
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

long long rev[201111], f[201111], ans, MOD=1000000009;
int n, a, b;

long long fast_mod(long long x, long long y) {
    if (y == 0) {
        return 1LL;
    }
    long long ret = fast_mod(x, y >> 1);
    ret = ret*ret%MOD;
    if (y & 1) {
        ret *= x;
        ret %= MOD;
    }
    return ret;
}

long long C(long long x, long long y) {
    if (x < y) return 0;
    return f[x]*rev[y]%MOD*rev[x-y]%MOD;
}

void work() {
    scanf("%d%d%d", &n, &a, &b);
    f[0] = rev[0] = 1;
    for (int i = 1; i <= a+b; ++i) {
        f[i] = f[i-1] * i % MOD;
        rev[i] = fast_mod(i, MOD-2) * rev[i-1] % MOD;
    }
    int s = max(n - a, 1);
    int t = min(b, n - 2);
    for (int k = 1; k <= n; ++k) {
        ans += C(b-1, k-1) * C(a-1, n-k-1) % MOD * (n-k-1) % MOD;
        ans %= MOD;
    }
    printf("%lld\n", ans*f[a]%MOD*f[b]%MOD);
}

int main() {
    int TestCase = 1;
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}