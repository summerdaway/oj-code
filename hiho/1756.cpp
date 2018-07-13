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

long long ans, sum, t;
int n, a[101111];
const long long MOD = 1000000007;

long long fast_mod(long long x, long long y) {
    if (y == 0) {
        return 1LL;
    }
    long long ret = fast_mod(x, y>>1);
    ret = ret*ret%MOD;
    if (y&1) {
        ret = ret*x%MOD;
    }
    return ret;
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    sum = 0, t = 1;
    for (int i = 0; i < n; ++i) {
        ans += fast_mod(2, i) * a[i] % MOD;
        ans %= MOD;
        if (i == 0 || a[i] != a[i-1]) {
            int ct = 0;
            for (int j = i; j < n && a[j] == a[i]; ++j) {
                ct += 1;
            }
            sum = sum*fast_mod(2, ct)%MOD + t*(fast_mod(2, ct) - 1) % MOD;
            printf("sum=%lld\n", sum);
            sum %= MOD;
        }
        t = t*2%MOD;

    }
    printf("ans=%lld\n", ans);
    ans = (ans-sum)%MOD;
    printf("%lld\n", (ans+MOD)%MOD);

}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}