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

int n, m;
pair<int, long long> a[101111];
long long ans, s[100];

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].first);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        long long w;
        scanf("%d%d%lld", &x, &y, &w);
        a[x].second ^= w;
        a[y].second ^= w;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < 61; ++j) {
            if ((a[i].second >> j) & 1) {
                a[i].second ^= s[j];
            }
        }
        if (a[i].second) {
            ans += a[i].first;
            for (int j = 0; j < 61; ++j) {
                if (!s[j] && (((a[i].second)>>j) & 1)) {
                    s[j] = a[i].second;
                    break;
                }
            }
        } else {
            ans -= a[i].first;
        }
    }
    printf("%lld\n", ans);
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
