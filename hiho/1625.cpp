
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
