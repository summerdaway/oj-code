
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

char a[101111];
int n, b[101111][300], ans, h[300];

void work() {
    scanf("%s", a);
    n = strlen(a);
    for (int i = 0; i < 300; ++i) {
        b[n][i] = n;
    }
    for (int i = n - 1; i >= 0; --i) {
        memcpy(b[i], b[i+1], sizeof(b[i+1]));
        b[i][a[i+1]] = i + 1;
    }
    memset(h, -1, sizeof(h));
    int cur = -1, st = -1;
    for (int i = 0; i < n; ++i) {
        char x = a[i];
        if (cur == -1) {
            ans++;
            if (h[x] == -1) {
                h[x] = i;
            } else {
                cur = h[x];
                st = i;
            }
        } else {
            if (b[cur][a[i]] >= st) {
                cur = -1;
                --i;
            } else {
                cur = b[cur][a[i]];
            }
        }
    }
    printf("%d\n", ans);
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
    给一个串S，求从空串变换到S的最小次数，可选操作有两种：
    1. 在当前字符串后面添加一个字符
    2. 选择当前字符串的一个子序列，接到当前字符串后面
    $|S| \le 10^5$
}_<

Solution >_{
    贪心。把S从前往后扫一遍，对于当前的字符x，如果x没在前面出现过，那么只能新加字符x。否则就找到x的第一个出现位置 $i_0$，接下来看S的下一个字符 y，如果 $i_0$ 后面出现了 y，就找到第一个出现位置 $i_1$，以此类推。也就是找最长的一段，它作为子序列在前面出现过，就把它复制一遍。
    做法是记a[i][x]表示i这个位置后面，字符x第一次出现的位置，每次直接跳到这个位置，这样可以做到O(n)的复杂度
}_<
*/


