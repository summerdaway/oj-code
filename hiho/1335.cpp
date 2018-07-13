
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

int n, f[11111], m;
map<string, int> g;
char ch[11111][100];
vector<int> a[101111];
char t[100];

int find(int x) {
    return x == f[x]? x: f[x] = find(f[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x > y) swap(x, y);
    f[y] = x;
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i ){
        scanf("%s", ch[i]);
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            scanf("%s", t);
            if (g[t] == 0) {
                g[t] = ++m;
            }
            a[g[t]].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < a[i].size(); ++j) {
            Union(a[i][j], a[i][j-1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (find(i) == i) {
            printf("%s", ch[i]);
            for (int j = i+1; j < n; ++j) {
                if (find(j) == i) {
                    printf(" %s", ch[j]);
                }
            }
            printf("\n");
        }
    }
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
    给$n$个名字，每个名字下有多个邮箱，合并邮箱相同的名字
    $n\le10000$, 每人最多10个邮箱
}_<

Solution >_{
    并查集
}_<

*/

