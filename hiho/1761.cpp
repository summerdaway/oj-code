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

int x, t, n, a[2000];

void calc(int l, int r) {
    if (l + 1 == r) return;
    calc(l, (l+r)>>1);
    calc((l+r)>>1, r);
    int mid = (l+r)>>1;
    for (int i = l; i < mid; ++i) {
        swap(a[i], a[i+mid-l]);
    }
}

void work() {
    scanf("%d%d", &x, &t);
    n = 1<<x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (t & 1) {
        calc(0, n);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", a[i]);
    }

}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}