#prag\
ma GCC optimize ("O2") 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, ans, a[101111], b[101111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int l = 0, r = ans + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (b[mid] > a[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        b[l+1] = a[i];
        ans = max(ans, l+1);
    }
    printf("%d\n", n - ans);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
