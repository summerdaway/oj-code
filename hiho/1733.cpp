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

int n, m, b[11111], a[10111];
long long s[10111], t[10111], MOD=1000000007;

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[j]);
        }
        memset(t, 0, sizeof(t));
        sort(b, b + m);
        if (i) {
            for (int j = 0; j < m; ++j) {
                int idx = lower_bound(a, a + m, b[j]) - a;
                if (idx) {
                    t[j] = s[idx-1];
                }
            }
        } else {
            for (int j = 0; j < m; ++j) {
                t[j] = 1;
            }
        }
        for (int j = 1; j < m; ++j) {
            t[j] += t[j-1];
            t[j] %= MOD;
        }
        memcpy(s, t, sizeof(s));
        memcpy(a, b, sizeof(a));
    }
    printf("%lld\n", s[m-1]);

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
