#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int n, m, ct[70000];
int b[31111][1000], ans[31111][1000];

struct Node {
    int a[5], label;
} a[31111];

bool cmp(const Node &a, const Node &b) {
    return a.a[0] < b.a[0];
}

void insert(int t, int i) {
    int _ = t/32, __ = t % 32;
    b[i][_] |= 1 << __;
}

void calc(int x) {
    for (int i = 0; i < n; ++i) {
        swap(a[i].a[0], a[i].a[x]);
    }
    sort(a, a + n, cmp);

    memset(b[0], 0, sizeof(b[0]));

    for (int i = 1; i < n; ++i) {
        memcpy(b[i], b[i-1], sizeof(b[i-1]));
        insert(a[i-1].label, i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[a[i].label][j] &= b[i][j];
        }
    }
}

int count(int x) {
    int ret = 0;
    while (x != 0) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}


int count1(int x) {
    int ret = 0;
    while (x) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

void work() {
    for (int i = 1 << 16; i; --i) {
        ct[i] = count1(i);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &a[i].a[j]);
        }
        a[i].label = i;
    }

    m = n/32 + 1;
    //printf("m=%d\n", m);

    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < 5; ++i) {
        calc(i);
    }

    for (int i = 0; i < n; ++i) {
        int ret = 0;
        for (int j = 0; j < m; ++j) {
            //printf("%d %d\n", ans[i][j] >> 16, ans[i][j] & ((1<<16)-1));
            ret += ct[(ans[i][j] >> 16) & ((1<<16) - 1)] + ct[ans[i][j] & ((1<<16) - 1)];
        }
        printf("%d\n", ret);
    }

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}