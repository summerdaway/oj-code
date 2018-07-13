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


int n, q, m;
long long s[100100];
pair<int, int> b[100100];
pair<long long, long long> a[101111];

void work() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &b[i].first, &b[i].second);
    }
    sort(b, b + n);

    int l = 1;
    for (int i = 0; i < n; ++i) {
        int x = b[i].first;
        int y = b[i].second;
        while (i + 1 < n && y >= b[i+1].first) {
            ++i;
            y = max(y, b[i].second);
        }
        y = max(b[i].second, y);
        if (l < x) {
            a[m++] = make_pair(l, x - 1);
        }
        l = y + 1;
    }
    if (1LL*l <= 10000000000LL) {
        a[m++] = make_pair(l, 10000000000LL);
    }
    for (int i = 0; i < m; ++i) {
        s[i] = a[i].second - a[i].first + 1;
        if (i) s[i] += s[i-1];
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        int idx = lower_bound(s, s + m, x) - s;
        long long r = a[idx].second;
        printf("%lld\n", r - (s[idx] - x));
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
