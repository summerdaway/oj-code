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

char a[201111], b[201111], c[201111];
int ans;

void work() {
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    int n = strlen(a);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i] && a[i] != c[i] && b[i] != c[i]) {
            ans += 2;
        } else if (a[i] == b[i] && a[i] == c[i]) {

        } else {
            ans += 1;
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
