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

int n, a[111];


void calc(int l, int r) {
    if (l == r) {
        return;
    }
    int x = -1;
    for (int i = l; i < r; ++i) {
        if (x == -1) {
            x = a[i];
        } else {
            x = min(x, a[i]);
        }
    }
    printf("%d\n", x);
    for (int i = l; i < r; ++i) {
        if (a[i] == x) {
            calc(l, i);
            calc(i + 1, r);
        }
    }
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    calc(0, n);
}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
