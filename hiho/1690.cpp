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

int n, f[10], ans;
char a[1001111];

void work() {
    scanf("%s", a);
    n = strlen(a);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'a') {
            f[0] += 1;
        } else if (a[i] == 'e') {
            f[1] = max(f[1], max(f[0], f[1]) + 1);
        } else if (a[i] == 'i') {
            f[2] = max(f[2], max(f[0], max(f[1], f[2])) + 1);
        } else if (a[i] == 'o') {
            f[3] += 1;
        } else {
            f[4] = max(f[4], max(f[3], f[4])+1);
        }
        ans = max(ans, max(f[0], max(f[1], f[2])) + max(f[3], f[4]));
    }
    printf("%d\n", ans);
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}