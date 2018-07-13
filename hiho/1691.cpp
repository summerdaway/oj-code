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

char a[11], b[11];
int ans, ct, n, c[11], v[11];

int calc(int x, int y) {
    int ret = abs(x - y);
    return ret > 5 ? 10 - ret : ret;
}

void work() {
    scanf("%d", &n);
    scanf("%s%s", a, b);
    for (int i = 0; i < n; ++i) {
        c[i] = i;
    }
    ans = 1000000;
    do {
        ct = 0;
        for (int i = 0; i < n; ++i) {
            ct += calc(a[c[i]]-'0', b[i]-'0');
        }
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                for (int j = c[i]; j != i; j = c[j]) {
                    v[j] = true;
                    ct += 1;
                }
                v[i] = true;
            }
        }
        ans = min(ans, ct);
    } while (next_permutation(c, c + n));
    printf("%d\n", ans);

}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}


/*
Problem >_{
    给长度为n的两个数a和b，两种操作：
    1. 将x变成y，代价是x按顺序数到y，例如0->1代价是1，9->2代价是3，3->5代价是2
    2. 交换两个数，代价是1
    $n\le 10$
}_<

Solution >_{
    枚举所有交换的permutation，直接计算
    注意不要漏掉permutation自己的代价
    搜索会超时
}_<