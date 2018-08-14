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
    一个长度为$n$的字符串，字符各不相同，每次选取连续$k$个字符，剪切下来，加到开头或结尾，可以反复做多次，求最后有多少个不同的字符串，输出mod p的余数。
    $1\le k\le n\le 10^7, 1\le p\le 10^9$
}_<

Solution >_{
    打表找规律
}_<
*/
