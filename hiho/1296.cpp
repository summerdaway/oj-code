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


void work() {
    long long n;
    int k;
    scanf("%lld%d", &n, &k);
    int sum = 0;
    for (int i = 2; i < k; ++i) {
        sum += k % i;
    }
    printf("%lld\n", ((n-k)*k + sum) % n);

}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int Test = 1;
    scanf("%d", &Test);
    while (Test--) {
        work();
    }
    return 0;
}

/*
Problem >_{
    给n和k，求长度为n，每报k个数就踢掉的约瑟夫环最后剩下的是谁
}_<

Solution >_{
    考虑$f(n, k)$表示答案，第一次报数之后，$k-1$被踢掉，剩下了$n-1$个人，从$k$开始报数，那么剩下的人的答案是$(f(n-1, k)+k) % n$，可以得到$f(n, k)=(f(1, k)+(n-1)k) % n$
}_<
*/