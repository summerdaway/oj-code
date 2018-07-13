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

int n, a[101001], b[101001], ct[1001111], ans, R[1001111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ct[a[i]] += 1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1000010; i >= 0; --i) {
        if (ct[i+1]) {
            R[i] = R[i+1];
        } else {
            R[i] = i + 1;
        }
    }

    ans = 1;
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = b[i];
        int r1 = R[0];
        int ret = r1;
        if (y == r1) {
            ret = R[r1+1];
        }
        if (x < ret && ct[x] == 1 && x != y) {
            ret = x;
        }
        ans = max(ans, ret);
        // printf("%d %d %d %d %d\n", x, y, r1, ct[x], ret);
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
