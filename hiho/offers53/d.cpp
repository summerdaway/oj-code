#include <map>
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
#include <set>
using namespace std;


int n, m, p;
long long sum[1111], ans;
int a[1111][111], b[1111];

int fast_mod(int x, int y) {
    if (y == 0) {
        return 1;
    }
    int ret = fast_mod(x, y>>1);
    ret = ret*ret % p;
    if (y & 1) {
        ret = ret*x % p;
    }
    return ret;
}

void work() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i < p; ++i) {
        b[i] = fast_mod(i, p - 2);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j]*a[i][j];
        }
        // printf("%lld ", sum[i]);
    }
    // printf("\n");
    for (int i = 0; i < min(n, m); ++i) {
        int x = i;
        long long mx = 0, idx = -1;
        for (int j = x; j < n; ++j) {
            if (a[j][x] != 0 && sum[j] > mx) {
                mx = sum[j];
                idx = j;
            }
        }
        if (idx == -1) continue;
        // printf("x=%d idx=%d sum=%lld\n", x, idx, mx);
        for (int j = 0; j < m; ++j) {
            swap(a[x][j], a[idx][j]);
        }

        // for (int j = 0; j < n; ++j) {
        //     for (int k = 0; k < m; ++k) {
        //         printf("%d ", a[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        swap(sum[x], sum[idx]);

        ans += sum[x];

        int niyuan = b[a[x][x]];
        // printf("NIYUAN=%d\n", niyuan);
        for (int j = 0; j < m; ++j) {
            a[x][j] *= niyuan;
            a[x][j] %= p;
        }

        // for (int j = 0; j < n; ++j) {
        //     for (int k = 0; k < m; ++k) {
        //         printf("%d ", a[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        for (int j = 0; j < n; ++j) {
            if (j == x) continue;
            int tmp = -a[j][x];
            for (int k = 0; k < m; ++k) {
                a[j][k] += tmp * a[x][k];
                a[j][k] = (a[j][k]%p + p) % p;
            }
        }
        // printf("result-------\n");
        // for (int j = 0; j < n; ++j) {
        //     for (int k = 0; k < m; ++k) {
        //         printf("%d ", a[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }
    printf("%lld\n", ans);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = clock();
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}