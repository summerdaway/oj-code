#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, l, r;
long long ans;
pair<int, int> a[101111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].first = x - y;
        a[i].second = x + y;
    }
    sort(a, a + n);
    l = a[0].first, r = a[0].second;
    ans = 1LL*(r-l)*(r-l);
    for (int i = 1; i < n; ++i) {
        //l = max(l, a[i].first);
        if (a[i].second < r) continue;
        ans += 1LL*(a[i].first-a[i].second)*(a[i].first-a[i].second);
        if (r > a[i].first) {
            ans -= 1LL*(r-a[i].first)*(r-a[i].first);
        }
        //l = max(l, r);
        r = max(r, a[i].second);
    }
    printf("%.2lf\n", 1.0*ans/4);
}

int main() {

    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}