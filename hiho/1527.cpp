#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

char ch[1001111];
int n, a[1001111], f[1001111][2], prev1[1001111];

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    for (int i = 0; i < n; ++i) {
        a[i+1] = ch[i] - '0';
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i-1] == 0) {
            prev1[i] = i - 1;
        } else {
            prev1[i] = prev1[i-1];
        }

    }

    f[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i][1] =  min(f[i-1][a[i-1]], f[prev1[i]][1]) + 1;
        f[i][0] = f[i-1][a[i-1]];
    }
    printf("%d\n", f[n][a[n]]*2-1);


}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}