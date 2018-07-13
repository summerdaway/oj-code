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


int f(long long x) {
    int ret = 0;
    while (x) {
        ret += (x%10)*(x%10);
        x /= 10;
    }
    return ret;
}

void work() {
    int ans = 0;
    long long k, a, b;
    scanf("%lld%lld%lld", &k, &a, &b);
    for (int i = 1; i < 1800; ++i) {
        long long n = k * i;
        if (f(n) == i && a <= n && n <= b) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
