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

long long n, d;

bool check(long long x) {
    long long tot = 1 + x;
    for (long long i = 2; i < d && x; ++i) {
        if (x >= 1<<30) return true;
        tot += x*(x-1);
        if (tot >= n) return true;
        x -= 1;
    }
    return false;
}

void work() {
    long long x = 1 + 23423423400000LL;
    printf("%lld\n", x);
    scanf("%lld%lld", &n, &d);
    long long l = 0, r = n - 1;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%lld\n", r);
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