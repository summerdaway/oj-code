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

int n, p[41111], v[41111], a[1000111], ans, ct[1000111], l, r;

void work() {
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; ++i) {
        a[i-l] = i;
    }

    v[1] = v[0] = true;
    for (int i = 2; i <= 40000; ++i) {
        if (!v[i]) {
            p[n++] = i;
            for (int j = i+i; j <= 40000; j += i) {
                v[j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int x = p[i];
        int j = l/x;
        if (l % x != 0) ++j;
        j *= x;
        for (; j <= r; j += x) {
            while (a[j-l] % x == 0) {
                a[j-l] /= x;
                ct[j-l] += 1;
            }
        }
    }
    for (int i = l; i <= r; ++i) {
        if (a[i-l] != 1) {
            ct[i-l] += 1;
        }
        if (!v[ct[i-l]]) ans += 1;
    }

    printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1, Case = 0;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        Case ++;
        //printf("Case #%d: ", Case);
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
