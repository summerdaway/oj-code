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

void work() {
    int n;
    scanf("%d", &n);
    int t = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        t ^= x;
    }
    if (n == 1) {
        printf("0\n");
        return;
    }
    if (!t) {
        printf("%lld\n", (1LL << n) - 2);
    } else {
        printf("0\n");
    }


}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}

/*
Problem >_{
    给n个数，要划分成两个集合A和B，满足A中数的异或和等于B中数的异或和，求划分的方法数，A和B都不能为空。$n\le50$
}_<

Solution >_{
    观察一下可以知道n个数的异或和必须为0，然后随意划分，两个集合不为空就可以
    如果n个数异或和不为0，那么答案是0
    否则考虑集合A，有$2^n-2$（减去空集和全集）种选择
}_<
*/
