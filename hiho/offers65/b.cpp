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

int n, Min[211111], a[211111];
long long S;
pair<long long, int> s[211111];

void work() {
    scanf("%d%lld", &n, &S);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i].first = s[i-1].first + a[i];
        s[i].second = i;
    }
    sort(s, s + n + 1);
    Min[n] = s[n].second;
    for (int i = n - 1; i >= 0; --i) {
        Min[i] = min(Min[i+1], s[i].second);
    }
    int j = 0, ans = 0;
    for (int i = 0; i <= n; ++i) {
        while (j <= n && s[i].first - s[j].first > S) ++j;
        if (j > n) break;
        ans = max(ans, s[i].second - Min[j]);
    }
    if (ans > 0) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }




}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
