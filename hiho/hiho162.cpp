#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

char a[111];
int n, f[111][111];
bool v[111][111];

int dp(int l, int r) {
    if (l >= r || v[l][r]) return f[l][r];
    v[l][r] = true;
    int &ret = f[l][r];
    if (a[l] == a[r]) {
        ret = dp(l + 1, r - 1);
    } else {
        ret = min(dp(l + 1, r), min(dp(l + 1, r - 1), dp(l, r - 1))) + 1;
    }
    return ret;
}

void work() {
    scanf("%s", a);
    n = strlen(a);
    for (int i = n; i; --i) {
        a[i] = a[i-1];
    }
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        f[i][i] = 0;
        f[i][i-1] = 0;
    }
    printf("%d\n", dp(1, n));
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}