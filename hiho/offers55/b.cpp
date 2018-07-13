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


map<long long, int> f;
int n, m, ans;
long long p[20], b[21111];
char a[21111][20];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        long long x = 0;
        m = strlen(a[i]);
        for (int j = m - 1; j >= 0; --j) {
            x *= 26;
            x += a[i][j] - 'a';
        }
        b[i] = x;
    }
    for (int i = 0; i < m; ++i) {
        if (i) p[i] = p[i-1] * 26;
        else p[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                long long x = b[i] / p[j] % 26, y = b[i] / p[k] % 26;
                long long t = b[i] - x * p[j] - y * p[k] + x * p[k] + y * p[j];
                ans += f[t];
            }
        }
        f[b[i]] += 1;
    }
    printf("%d\n", ans);
}

int main() {
    // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
