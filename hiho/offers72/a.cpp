#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, k;
long long P;

void work() {
    scanf("%d%d%lld", &n, &k, &P);
    if (n == k) {
        printf("1\n");
    } else if (n - 1 == k) {
        printf("%d\n", n%P);
    } else {
        long long ans = 1;
        for (int i = 3; i <= n; ++i) {
            ans *= i;
            ans %= P;
        }
        if (k & 1) {
            printf("%lld\n", (ans<<1)%P);
        } else {
            printf("%lld\n", ans);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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

/*
Problem >_{
    $n*m$ 矩阵，每个位置有值 $a_{ij}$，求一个面积不小于 $S$ 的子矩阵，使 $\sum a_{ij}$ 最大
    $1\le n, m\le300$
    $1\le S \le 90000$
    $|a_{ij}|\le 10^4
}_<

Solution >_{
    枚举左边线$i$和右边线$j$，矩阵宽为$j-i+1$，可以算出最小长度$L$，记一下 $k-L$ 之间的和的最小值，用当前和减掉最小值求最大
}_<
*/
