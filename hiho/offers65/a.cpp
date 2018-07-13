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

bool v[1001111];
int ct, p[10], a[50], n;

bool check(int x) {
    for (int i = 0; i < 9; ++i) {
        if (p[i] > x) break;
        for (int j = i + 1; j < 9; ++j) {
            int y = x % p[j] / p[i];
            if (v[y]) return false;
        }
    }
   return true;
}

void work() {
    p[0] = 1;
    for (int i = 1; i < 9; ++i) {
        p[i] = p[i-1] * 10;
    }
    v[0] = v[1] = true;
    for (int i = 2; i < 1000000; ++i) {
        if (!v[i]) {
            for (int j = i*2; j < 1000000; j += i) {
                v[j] = true;
            }
        }
    }
    for (int i = 2; i < 1000000; ++i) {
        if (check(i)) {
            a[n++] = i;
        }
    }
    int x;
    scanf("%d", &x);
    if (x <= n) {
        printf("%d\n", a[x-1]);
    } else {
        printf("-1\n");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
