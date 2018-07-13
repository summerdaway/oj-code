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


int MAXINT = 1000000002;
long long ans, sum;
int n, k, a[51111], l[51111][4], r[51111][4];

void work() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    l[0][0] = l[0][1] = l[0][2] = MAXINT;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            l[i][j] = l[i-1][j];
        }
        l[i][3] = a[i];
        for (int j = 2; j >= 0; --j) {
            if (l[i][j] > l[i][j+1]) {
                swap(l[i][j], l[i][j+1]);
            }
        }
    }
    r[n+1][0] = r[n+1][1] = r[n+1][2] = -MAXINT;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < 3; ++j) {
            r[i][j] = r[i+1][j];
        }
        r[i][3] = a[i];
        for (int j = 2; j >= 0; --j) {
            if (r[i][j] < r[i][j+1]) {
                swap(r[i][j], r[i][j+1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        long long x = sum;
        for (int j = 0; j < k; ++j) {
            if (l[i][j] != MAXINT && r[i+1][j] != -MAXINT) {
                x += r[i+1][j] - l[i][j];
            }
        }
        ans = max(ans, x);
    }
    printf("%lld\n", ans);

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
