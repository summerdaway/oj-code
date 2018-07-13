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

int n, p1[101111], p2[101111], f[101111], a[101111], cur[101111], p[101111];
long long g[101111], Sum[101111];
long long MOD = 1000000007;
bool v[101111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    memset(cur, -1, sizeof(cur));
    for (int i = 0; i < n; ++i) {
        p1[i] = cur[a[i]];
        cur[a[i]] = i;
    }
    memset(cur, -1, sizeof(cur));
    for (int i = n - 1; i >= 0; --i) {
        p2[i] = cur[a[i]];
        cur[a[i]] = i;
    }
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (v[a[i]]) {
            prev++;
            while (a[prev] != a[i]) {
                v[a[prev]] = false;
                prev++;
            }
        }
        p[i] = prev;
        v[a[i]] = true;
    }

    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            f[i] = 1;
        } else {
            if (f[i] == -1) f[i] = f[p[i]] + 1;
            else f[i] = min(f[i], f[p[i]] + 1);
        }
    }

    prev = 0;
    for (int i = 0; i < n; ++i) {
        // g[i] = sum(g[j], f[j]+1=f[i] && j>=p[i])
        if (p[i] == -1) {
            g[i] = 1;
            Sum[f[i]] += g[i];
            Sum[f[i]] %= MOD;
        } else {
            for(int j = max(0, p[i-1]); j < p[i]; ++j) {
                Sum[f[j]] -= g[j];
                Sum[f[j]] %= MOD;
            }
            g[i] += Sum[f[i]-1];
            Sum[f[i]] += g[i];
            Sum[f[i]] %= MOD;
        }
    }
    printf("%d %lld\n", f[n-1], (g[n-1]+ MOD)%MOD);

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
