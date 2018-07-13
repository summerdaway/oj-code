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

int n, ans;
char a[201111], b[201111];

void work() {
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    n = strlen(a);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ans++;
            while (i < n && b[i] != a[i]) ++i;
            --i;
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
