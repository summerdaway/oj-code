#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m, a[111][111], b[10], c[10], d, e, ans;

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                b[k] = c[k] = 0;
            }
            d = e = 0;
            for (int k = 0; k < 3; ++k) {
                for (int o = 0; o < 3; ++o) {
                    b[k] += a[i+k][j+o];
                    c[k] += a[i+o][j+k];
                }
                d += a[i+k][j+k];
                e += a[i+k][j+2-k];
            }
            bool flag = d == e;
            for (int k = 0; k < 3; ++k) {
                flag &= d == b[k];
                flag &= d == c[k];
            }
            if (flag) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}


/*
Problem >_{
    给$n\times m$的矩阵，找多少个$3\times 3$的子矩阵是三阶幻方：行列斜的和都相等
}_<

Solution >_{
    枚举，分别算行列的和，斜向的和记成两个数
}_<

*/