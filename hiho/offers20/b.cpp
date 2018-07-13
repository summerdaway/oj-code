#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, ans;

void work() {
    scanf("%d", &n);
    s = n<<1;
    ans = -1;
    for (int i = 1; i*i <= s; ++i) {
        if (s % i != 0) continue;
        int t = s/i;
        if (((s/t + 1 - t) % 2 == 0) && i + 1 > t) {
            ans = max(ans, t);
        }
        if (((s/i + 1 - i) % 2 == 0) && t + 1 > i) {
            ans = max(ans, i);
        }
    }
    printf("%d\n", ans);
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
    return 0;
}