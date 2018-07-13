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

int n, p, q, k, a[111], ans;

void work() {
    scanf("%d%d%d%d", &n, &p, &q, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    if (k == 0) {
        for (int i = 0; i < q; ++i) {
            ans -= a[i];
        }
        for (int i = q; i < n; ++i) {
            ans += a[i];
        }
        printf("%d\n", ans);
    } else {
        ans -= a[0];
        for (int i = 1; i < n; ++i) {
            ans += a[i];
        }
        printf("%d\n", ans);
    }

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
