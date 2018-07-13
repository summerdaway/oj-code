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

int n, a, b, ans;


void work() {
    scanf("%d%d%d", &n, &a, &b);
    for (int y = 1; y <= n; ++y) {
        for (int x = y; x; x = (x-1)&y) {
            ans = max(ans, (a*x+b*y)^(a*y+b*x));
        }
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
