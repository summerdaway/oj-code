
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


int n, f[2111][2111], g[2111][2111], T1[5000], T2[5000], ans, q, a[2111], b[2111], c[5000], m, p, gg[2111], ff[2111];
map<int, int> F;

void add1(int x, int y) {
    for (int i = x; i <= q; i += i&(-i)) {
        T1[i] = max(T1[i], y);
    }
}

int query1(int x) {
    int ret = 0;
    for (int i = x; i; i -= i&(-i)) {
        ret = max(T2[i], ret);
    }
    return ret;
}

void add2(int x, int y) {
    for (int i = x; i <= q; i += i&(-i)) {
        T2[i] = max(T2[i], y);
    }
}

int query2(int x) {
    int ret = 0;
    for (int i = x; i; i -= i&(-i)) {
        ret = max(T1[i], ret);
    }
    return ret;
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        c[p++] = a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        c[p++] = b[i];
    }
    sort(c, c + p);
    for (int i = 0; i < p; ++i) {
        if (F[c[i]] == 0) {
            F[c[i]] = ++q;
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] = F[a[i]];
    }
    for (int i = 0; i < m; ++i) {
        b[i] = F[b[i]];
    }
    for (int i = 0; i < n; ++i) {
        memset(T1, 0, sizeof(T1));
        memset(T2, 0, sizeof(T2));
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                f[i][j] = query1(q-a[i]) + 1;
                g[i][j] = query2(a[i]-1) + 1;
                ff[j] = max(ff[j], f[i][j]);
                gg[j] = max(gg[j], g[i][j]);

                ans = max(f[i][j], ans);
                ans = max(g[i][j], ans);
            }                
            add1(b[j], ff[j]);
            add2(q-b[j]+1, gg[j]);
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
    给两个序列$a_i$和$b_j$，长度分别为n和m，要找一条波浪c，满足c是a和b的公共子序列。波浪定义是对任意$c_i$满足 $c_{i-1} < c_i > c_{i+1}$ 或 $c_{i-1} > c_i < c_{i+1}$
    $n, m \le 1000$
    $a_i, b_j \le 10^9$
}_<

Solution >_{
    f(i, j, t)表示 $a_i$ 和 $b_j$ 匹配，t 表示最后一个数是上升还是下降的，最大长度。$f(i, j, t) = \max{f(x, y, 1-t), x<i, y<j}$
    树状数组记T(x, t)，可以求小于x的最大值，O(nmlogn)
    （循环时，i 固定，枚举 j，每次查询的都是 $a_i$，所以可以不用树状数组记，优化到O(nm)）
}_<
*/