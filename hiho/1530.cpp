#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

long long a, b, p;

long long fast_mod(long long x, long long y, long long MOD) {
    if (y == 0) return 1LL;
    long long ret = fast_mod(x, y >> 1, MOD);
    ret = ret * ret % MOD;
    if (y & 1) ret = ret * x % MOD;
    return ret;
}

void work() {
    cin >> a >> b >> p;
    printf("%lld\n", a * fast_mod(b, p - 2, p) % p);

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}