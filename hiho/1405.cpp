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

int n, a[111];

void dfs(int l, int r) {
    if (l == r) return;
    int mn = 1000001, x = -1;
    for (int i = l; i < r; ++i) {
        if (a[i] < mn) {
            mn = a[i];
            x = i;
        }
    }
    printf("%d", mn);
    --n;
    printf(n==0?"\n":" ");
    dfs(l, x);
    dfs(x+1, r);
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    dfs(0, n);
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}


/*
Problem >_{
    给一个数组，是一个堆的中序遍历，求这个堆的先序遍历
}_<

Solution >_{
    每次找区间的最小值作为根，分成左右两部分递归做
}_<

*/