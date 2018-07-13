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

int a[120][120], b[120], n, m, K, ans;
int MOD = 1000000009;


void work() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        b[x%K] += 1;
    }
    a[0][0] = 1;
    for (int i = 1; i <= 110; ++i) {
        for (int j = 0; j <= i; ++j) {
            a[i][j] = a[i-1][j];
            if (j) a[i][j] += a[i-1][j-1];
            a[i][j] %= MOD;
        }
    }
    ans = 0;
    for (int i = 0; i < K; ++i) {
        ans += a[b[i]][m];
        ans %= MOD;
    }
    printf("%d\n", ans);
}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
