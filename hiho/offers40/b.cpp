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

int n;
void work() {
    scanf("%d", &n);
    while (n--){ 
        long long x;
        int k;
        scanf("%lld%d", &x, &k);
        long long t = 1;
        bool flag = false;
        for (long long y = x; y >= max(x - 10000, 1LL); y -= 2) {
            if (t == k) {
                printf("%lld\n", y);
                flag = true;
                break;
            }
            t = t * y % 10;
        }
        if (!flag) {
            printf("-1\n");
        }

    }
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}