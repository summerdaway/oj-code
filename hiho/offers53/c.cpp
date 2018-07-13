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

const int maxn = 101111;

int n, a[maxn], f[maxn], g[maxn], ans;
int T[120000];

int query(int x) {
    int ret = 0;
    for (int i = x; i; i -= i&(-i)) {
        ret = max(T[i], ret);
    }
    return ret;
}

void insert(int x, int y) {
    for (int i = x; i <= 110000; i += i&(-i)) {
        T[i] = max(T[i], y);
    }
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        f[i] = query(100000 - a[i] + 1) + 1;
        insert(100000 - a[i] + 1, f[i]);
        if (i) f[i] = max(f[i], f[i-1]);
    }
    memset(T, 0, sizeof(T));
    for (int i = n - 1; i >= 0; --i) {
        g[i] = query(a[i]) + 1;
        insert(a[i], g[i]);
        g[i] = max(g[i], g[i+1]);
    }
    ans = max(g[0], f[n-1]);
    for (int i = 1; i < n; ++i) {
        ans = max(ans, f[i-1] + g[i]);
    }
    // for (int i = 0; i < n; ++i) {
    //     printf("%d %d\n", f[i], g[i]);
    // }
    printf("%d\n", ans);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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
