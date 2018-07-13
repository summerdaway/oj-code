#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int n;
long long K, ans;
const long long MOD = 1000000007;   
long long a[101111];
map<long long, int> f;

long long fast_mod(long long x, long long y ) {
    if (y < 0) return 1LL;
    if (y == 0) return 1LL;
    long long ret = fast_mod(x, y >> 1);
    ret = ret*ret%MOD;
    if (y & 1) ret = ret* x %MOD;
    return ret;
}

void work() {
    scanf("%d%lld", &n, &K);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    int j = n;
    for (int i = 0; i < n; ++i) {
        while (j > i && a[j-1] + a[i] > K) --j;
        if (i >= j) continue;
        ans += fast_mod(2, j - i - 1);
        ans %= MOD;
    }
    printf("%lld\n", ans);
}


int main() {
    int TC = 1;
    while (TC--) {
        work();
    }

}