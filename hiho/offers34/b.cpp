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

int n, a[1001111], T[2001111], ans[2001111];

int query(int x) {
    int ret = -1;
    for (int i = x; i; i -= i & (-i)) {
        ret = max(ret, T[i]);
    }
    return ret;
}

void add(int x, int idx) {
    for (int i = x; i <= 1500000; i += i & (-i)) {
        T[i] = max(T[i], idx);
    }
}

void work() {
    memset(T, -1, sizeof(T));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] = 1000001 - a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = query(a[i]-1);
        if (ans[i] != -1) {
            ans[i] = n - ans[i] - i;
        }
        add(a[i], n - i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}