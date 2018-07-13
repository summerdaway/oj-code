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

int n, a[50], N, ans, f[67108865];
char ch[1000];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        for (int j = 0; j < strlen(ch); ++j) {
            a[i] |= 1 << (ch[j] - 'a');
        }
    }
    N = 1<<26;
    f[0] = 1;
    for (int i = 0; i < N; ++i) {
        if (!f[i]) continue;
        for (int j = 0; j < n; ++j) {
            if ((i & a[j]) == 0) {
                f[i|a[j]] = max(f[i|a[j]], f[i] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans - 1);
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
