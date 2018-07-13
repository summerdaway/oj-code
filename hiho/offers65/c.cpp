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

long long f[20][20], g[20][20], L, R, p[20], a[10000];
int m;

int get_x(long long x, int t) {
    return x/p[t]%10;
}


long long calc(long long x) {
    if (x == 0) return 0;
    int n = 0;
    long long t = x;
    while (t) {
        n++;
        t /= 10;
    }
    long long ret = 0;
    for (int i = 1; i < 10; ++i) {
        for (int j = n - 1; j; --j) {
            ret += f[j][i] + g[j][i];
        }
    }
    bool up = true;
    bool down = true;
    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1) {
            int t1 = get_x(x, i+1), t2 = get_x(x, i);
            if (up) {
                for (int j = t1; j < t2; ++j) {
                    ret += g[i+1][j];
                }
            }
            if (down) {
                for (int j = min(t1, t2-1); j >= 0; --j) {
                    ret += f[i+1][j];
                }
            }
            if (get_x(x, i+1) > get_x(x, i)) {
                up = false;
            }
            if (get_x(x, i+1) < get_x(x, i)) {
                down = false;
            }
        } else {
            for (int j = get_x(x, i)-1; j > 0; --j) {
                ret += f[i+1][j] + g[i+1][j];
            }
        }
    }
    if (up) ret ++;
    if (down) ret ++;
    for (int i = 0; i < m; ++i) {
        if (a[i] <= x) {
            ret--;
        }
    }
    return ret;

}

void work() {
    scanf("%lld%lld", &L, &R);
    printf("%lld\n", calc(R) - calc(L-1));

}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    for (int i = 0; i < 10; ++i) {
        f[1][i] = 1;
        g[1][i] = 1;
    }
    for (int i = 2; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (k <= j) {
                    f[i][j] += f[i-1][k];
                }
                if (k >= j) {
                    g[i][j] += g[i-1][k];
                }
            }
        }
    }
    p[0] = 1;
    for (int i = 1; i < 20; ++i) {
        p[i] = p[i-1] * 10;
    }
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 19; ++j) {
            for (int k = 0; k < j; ++k) {
                a[m] += p[k]*i;
            }
            m++;
        }
    }
    scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
