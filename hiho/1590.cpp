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

struct Node {
    int max, mark;
} T[5001111];
struct Node1 {
    int x, y;
} a[101111], c[101111];
int b[301111], n, m, q, N, p;
map<int, int> f;

void pass(int node) {
    int lc = node<<1, rc = (node<<1)+1;
    T[lc].mark += T[node].mark;
    T[rc].mark += T[node].mark;
    T[lc].max += T[node].mark;
    T[rc].max += T[node].mark;
    T[node].mark = 0;
}

int add(int node, int l, int r, int x, int y, int t) {
    // printf("node=%d l=%d r=%d x=%d y=%d max0=%d\n", node, l, r, x, y, T[node].max);
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) {
        T[node].mark += t;
        T[node].max += t;
        return T[node].max;
    }
    int mid = (l + r) >> 1;
    pass(node);
    int ret1 = add((node<<1), l, mid, x, y, t);
    int ret2 = add((node<<1)+1, mid+1, r, x, y, t);
    T[node].max = max(T[node<<1].max, T[(node<<1)+1].max);
    return max(ret1, ret2);
}


void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].y--;
        b[p++] = a[i].x;
        b[p++] = a[i].y;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &c[i].x, &c[i].y);
        c[i].y--;
        b[p++] = c[i].x;
        b[p++] = c[i].y;
    }
    sort(b, b + p);
    for (int i = 0; i < p; ++i) {
        if (f[b[i]] == 0) {
            f[b[i]] = ++N;
        }
    }
    // printf("N=%d\n", N);
    for (int i = 0; i < n; ++i) {
        // printf("%d %d %d %d\n", a[i].x, a[i].y, f[a[i].x], f[a[i].y]);
        add(1, 1, N, f[a[i].x], f[a[i].y], 1);
        // printf("\n");
    }
    for (int i = 0; i < q; ++i) {
        int tmp = add(1, 1, N, f[c[i].x], f[c[i].y], 0);
        if (tmp == m) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }


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