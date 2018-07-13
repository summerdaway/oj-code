#pragma GCC optimize(2)
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
#include <set>
using namespace std;


int T[20][2][101111], n;
long long ans;

void add(int k, int t, int x, int y) {
    for (int i = x; i <= 100000; i += i&(-i)) {
        T[k][t][i] += y;
    }
}

int query(int k, int t, int x) {
    int ret = 0;
    for (int i = x; i; i -= i&(-i)) {
        ret += T[k][t][i];
    }
    return ret;
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < 18; ++j) {
            if ((x >>j) & 1) {
                ans += (1LL * (query(j, 0, 100000) - query(j, 0, x))) << j;
            } else {
                ans += (1LL * (query(j, 1, 100000) - query(j, 1, x))) << j;
            }
            add(j, (x>>j) & 1, x, 1);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("1693.in", "r", stdin);
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}