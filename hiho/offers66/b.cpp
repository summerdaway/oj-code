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

int n, a[201111][3], max1, max2, ans;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &a[i][j]);
        }
        sort(a[i], a[i] + 3);
        max1 = max(max1, a[i][0]);
        max2 = max(max2, a[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i][1] > max1 && a[i][2] > max2) ans++;
    }
    printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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
