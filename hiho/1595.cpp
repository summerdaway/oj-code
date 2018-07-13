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

int n, k;
long long a[101111], s[101111];


void work() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    for (int i = 1; i < n; ++i) {
        s[i] = a[i] - a[i-1];
    }
    sort(s + 1, s + n);
    reverse(s + 1, s + n);
    long long ans = 0;
    for (int i = 1; i < k; ++i) {
        ans -= s[i];
    }
    printf("%lld\n", ans + a[n-1] - a[0]);

}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
