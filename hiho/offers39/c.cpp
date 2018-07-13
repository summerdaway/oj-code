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

long long n, k, l, r;
int m, N, p[50];
bool v[101111];

long long calc(long long x) {
    long long ret = x;
    for (int i = 1; i < N; ++i) {
        int ct = 0;
        long long t = 1;
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                t *= p[j];
                ct++;
            }
        }
        t = x / t;
        if (ct & 1) {
            ret -= t;
        } else {
            ret += t;
        }
    }
    return ret;
}

void work() {
    for (int i = 2; i <= 100000; ++i) {
        if (!v[i]) {
            for (int j = i<<1; j <= 100000; j += i) {
                v[j] = true;
            }
        }
    }

    scanf("%lld%lld", &n, &k);

    for (int i = 2; i <= 100000; ++i) {
        if (!v[i] && (n % i == 0)) {
            p[m++] = i;
        }
    }

    N = 1 << m;
    l = 1, r = n;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (calc(mid) < k) {
            l = mid; 
        } else {
            r = mid;
        }
    }

    printf("%lld\n", l + 1);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
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

