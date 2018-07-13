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

struct TT {
    int mark, x;
} T[5001111];
int n, m;

void pass_mark(int node, int mark) {
    T[node].mark = max(T[node].mark, mark);
    T[node].x = max(T[node].x, mark);
}

void add(int node, int l, int r, int x, int y, int t) {
    if (x <= l && r <= y) {
        T[node].x = t;
        T[node].mark = t;
        return;
    }
    if (x > r || y < l) {
        return;
    }
    if (T[node].mark) {
        pass_mark(node<<1, T[node].mark);
        pass_mark((node<<1)+1, T[node].mark);
        T[node].mark = 0;
    }
    int mid = (l + r) >> 1;
    add(node<<1, l, mid, x, y, t);
    add((node<<1)+1, mid+1, r, x, y, t);
    T[node].x = max(T[node<<1].x, T[(node<<1)+1].x);
}

int query(int node, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return T[node].x;
    }
    if (x > r || y < l) {
        return 0;
    }
    if (T[node].mark) {
        pass_mark(node<<1, T[node].mark);
        pass_mark((node<<1)+1, T[node].mark);
        T[node].mark = 0;
    }
    int mid = (l + r) >> 1;
    return max(query(node<<1, l, mid, x, y), query((node<<1)+1, mid + 1, r, x, y));
}

void work() {
    scanf("%d", &m);
    n = 100000;
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d %d\n", x, y);
        int t = query(1, 1, n, x, y) + 1;
        add(1, 1, n, x, y, t);
    }
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}