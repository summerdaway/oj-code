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

struct Node {
    int ll, rl, maxlen, len;
} T[2001111];
int n, a[101111], b[101111], c[101111], q;

Node merge(Node LN, Node RN) {
    Node ret;
    ret.maxlen = max(LN.maxlen, RN.maxlen);
    ret.maxlen = max(ret.maxlen, LN.rl + RN.ll);
    ret.ll = LN.ll;
    ret.rl = RN.rl;
    ret.len = LN.len + RN.len;

    if (LN.ll == LN.len) {
        ret.ll = LN.len + RN.ll;
    }
    if (RN.rl == RN.len) {
        ret.rl = RN.len + LN.rl;
    }
    return ret;
}

void build_tree(int node, int l, int r){
    if (l == r) {
        if (c[l] == 0) {
            T[node].ll = T[node].rl = T[node].maxlen = 1;
        }
        T[node].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    int LN = node<<1;
    int RN = (node<<1) + 1;
    build_tree(LN, l, mid);
    build_tree(RN, mid+1, r);
    T[node] = merge(T[LN], T[RN]);
}

Node query(int node, int l, int r, int x, int y) {
    //printf("l=%d r=%d x=%d y=%d\n", l, r, x, y);
    if (r < x || l > y || x > y) {
        Node ret = Node();
        return ret;
    }
    if (x <= l && r <= y) {
        return T[node];
    }

    int mid = (l + r) >> 1;

    Node retL = query(node<<1, l, mid, x, y);
    Node retR = query((node<<1)+1, mid+1, r, x, y);
    return merge(retL, retR);
}

void work() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        b[i] = a[i] - a[i-1];
    }
    for (int i = 2; i < n; ++i) {
        c[i] = b[i] - b[i-1];
    }
    build_tree(1, 2, n-1);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        if (x == y) {
            printf("1\n");
        } else {
            printf("%d\n", query(1, 2, n - 1, x + 2, y).maxlen + 2);
        }
    }
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}

/*
1 2 3 5 7 9 
  1 1 2 2 2
    0 1 0 0

10 9 8 7 6 3 5 7 9 11
  -1-1-1-1-3 2 2 2 2
     0 0 0-2 5 0 0 0
*/