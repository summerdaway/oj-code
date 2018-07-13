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

int n, m, p[1001111], b[1001111], ct, ans, x;
bool v[1001111];
long long sum, t, a[1111], mx;

int calc(long long x) {
    int ret = 0;
    while (x) {
        ret += x/5;
        x /= 5;
    }
    return ret;
}

void work() {
    for (int i = 2; i <= 1000000; ++i) {
        if (!v[i]) {
            for (int j = i; j <= 1000000; j += i) {
                v[j] = true;
            }
            p[m++] = i;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
        ct += calc(a[i]);
        if (a[i] > mx) {
            mx = a[i];
            x = i;
        }
    }
    if (calc(sum) > ct) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i != x) {
            for (int k = 2; k <= a[i]; ++k) {
                int y = k;
                for (int j = 0; j < m; ++j) {
                    while (y % p[j] == 0) {
                        b[j] -= 1;
                        y /= p[j];
                    }
                }
            }
        } else {
            for (long long k = sum; k > a[i]; --k) {
                t = k;
                for (int j = 0; j < m; ++j) {
                    while (t % p[j] == 0) {
                        b[j] += 1;
                        t /= p[j];
                    }
                }
            }
        }
    }
    ans = t%10;
    for (int i = 0; i < m; ++i) {
        while (b[i]) {
            ans *= p[i];
            ans %= 10;
            b[i]--;
        }
    }
    printf("%d\n", ans);
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        sum = mx = 0;
        memset(v, 0, sizeof(v));
        memset(b, 0, sizeof(b));
        m = 0;
        work();
    }
    return 0;
}