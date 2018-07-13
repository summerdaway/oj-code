
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


int n;
pair<long long, long long> a[101111];
long long ans, s[62];

void work() {
    scanf("%d", &n);
    n--;
    for (int i = 0; i < n; ++i) {
        long long x, y, w;
        scanf("%lld%lld%lld%lld", &x, &y, &a[i].second, &w);
        a[i].first = x^y^w;
        ans += a[i].first;
    }
    sort(a, a + n);
    reverse(a, a + n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a[i].second != 1) {
            flag = true;
            long long x = a[i].second;
            for (int j = 0; j < 61; ++j) {
                if ((x >> j) & 1) {
                    x ^= s[j];
                }
            }
            if (x) {
                ans -= a[i].first;
                for (int j = 0; j < 61; ++j) {
                    if (((x >> j) & 1) && (s[j] == 0)) {
                        s[j] = x;
                        break;
                    }
                }
            }
        }
    }
    if (!flag) {
        printf("No\n");
    } else {
        printf("%lld\n", ans);
    }

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
