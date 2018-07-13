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

int n, a[1000111], mx, ans;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    mx = a[n-1];
    for (int i = n - 2; i >= 0; --i) {
        if (mx > a[i]) {
            ans += (mx - a[i]);
        }
        mx = max(mx, a[i]);
    }
    printf("%d\n", ans);

}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}