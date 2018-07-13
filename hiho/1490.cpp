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

int n, m, K;
int T[111][111], a[111], d[111][111], fa[111], s[111], b[111];
bool leaf[111];

void add_node(int h) {
    //printf("h=%d x=%d\n", h, T[h][s[h]]);
    int dist = d[T[h][s[h]]][T[m-1][s[m-1]-1]];
    //printf("%d %d dist=%d\n", T[h][s[h]], T[m-1][s[m-1]-1], dist);
    dist = (dist - (m-1 - h))/2 - 1;
    while (dist) {
        s[h-1]++;
        while (leaf[T[h-1][s[h-1]]]) {
            add_node(h-1);
            s[h-1]++;
        }
        fa[T[h][s[h]]] = T[h-1][s[h-1]];
        h--;
        dist--;
    }
    fa[T[h][s[h]]] = T[h-1][s[h-1]];
}


void work() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < b[i]; ++j) {
            scanf("%d", &T[i][j]);
        }
    }

    for (int i = 0; i < K; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        leaf[x] = true;
    }

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            scanf("%d", &d[a[i]][a[j]]);
        }
    }

    for (int i = 1; i < m; ++i) {
        fa[T[i][0]] = T[i-1][0];
    }
    s[m-1] = 1;

    while (true) {
        bool flag = true;
        for (int i = m-1; i; --i) {
            //printf("i=%d %d\n", i, s[i]);
            if (s[i] != b[i]) {
                while (s[i] < b[i] && !leaf[T[i][s[i]]]) s[i]++;
                if (leaf[T[i][s[i]]]) {
                    add_node(i);
                    flag = false;
                    s[i]++;
                }
                break;
            }
        }
        if (flag) break;
    }



    for (int i = 1; i <= n; ++i) {
        printf("%d", fa[i]);
        printf(i == n? "\n": " ");
    }

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}