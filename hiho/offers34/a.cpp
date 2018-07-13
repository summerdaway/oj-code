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

int n;
long long s, m, k;

void work() {
    scanf("%d", &n);
    s = 0;
    m = 100000;
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        s += x;
        m = min(m, x);
    }
    k = s - m*(n-1);
    printf("%lld\n", k-m);
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}