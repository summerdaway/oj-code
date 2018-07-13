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

int n;
int a[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

bool check(int x) {
    int y = 0, t = x;
    while (t) {
        if (a[t%10] == -1) return false;
        y *= 10;
        y += a[t%10];
        t /= 10;
    }
    if (x%10 != 0 && y != x && y <= n) {
        return true;
    }
    return false;
}

void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (check(i)) {
            printf("%d\n", i);
        }
    }

}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    // scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
