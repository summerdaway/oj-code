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

long long n, phi;


long long fast_mod(int x, int y, long long MOD) {
    if (y == 0) {
        return 1LL;
    }
    long long ret = fast_mod(x, y>>1, MOD);
    ret = ret*ret % MOD;
    if (y & 1) {
        ret = ret*x % MOD;
    }
    return ret;
}

void work() {
    scanf("%lld", &n);
    if (n == 2) {
        printf("-1\n");
        return;
    }
    int nn = (int) sqrt(n);
    bool flag = true;
    for (int i = 2; i <= nn; ++i) {
        if (n % i == 0) {
            flag = false;
            phi = n/i*(i-1);
            break;
        }
    }
    if (flag) phi = n - 1;
    for (int i = 2; i < n; ++i) {
        long long tmp = (long long) i*i % n;
        if (tmp*tmp % n != i) continue;
        if (tmp*i % n != 1) continue;
        printf("1 %d %lld\n", i, tmp);
        return;
    }
    printf("-1\n");

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}