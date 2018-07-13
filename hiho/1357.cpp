#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int n, m, K, a[101111];
int MAX = 100000000;

bool check(int x) {
    int cur = m, k = K;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= cur) {
            cur = m;
            k--;
        } else {
            cur -= a[i];
            cur = min(m, cur + x);
        }
    }
    return k > 0;
}


void work() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 0, r = MAX;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", r);
    }

}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
