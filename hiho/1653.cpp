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

int n, a[201111];
long long ans;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < (n<<1); ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + (n<<1));
    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }
    printf("%lld\n", ans + a[(n<<1)-1] - a[0]);
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}