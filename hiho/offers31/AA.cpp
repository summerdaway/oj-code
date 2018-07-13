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

long long ans;
int n, a[101111], head, tail;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int l = a[i]/8+8;
        if (a[i] % 8) l++;
        int r = a[i]*8+8;
        if (a[i] < 88888) r = min(r, 88888);
        int ll = lower_bound(a, a + n, l) - a;
        int rr = upper_bound(a, a + n, r) - a;
        ans += rr-ll;
        if (ll <= i && i < rr) ans--;
    }
    printf("%lld\n", ans);
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
