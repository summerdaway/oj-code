#include <cstdio>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

char ch[1111];
int a[1111], b[1111], n, ans;

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    for (int i = 0; i < n; ++i) {
        a[i] = ch[i] != '0';
        if (i > 0) {
            a[i] += a[i-1];
        }
    }

    b[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = ch[i] != '1';
        if (i < n - 1) {
            b[i] += b[i+1];
        }
    }

    ans = b[0];
    for (int i = 0; i < n; ++i) {
        ans = min(ans, a[i] + b[i+1]);
    }
    printf("%d\n", ans);
}


int main() {
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}