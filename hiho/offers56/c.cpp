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

int fa[101111], n, q;
char ch[10];
set<int> s[101111];

int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    fa[x] = find(fa[x]);
    int y = fa[x];
    for (set<int>::iterator iter = s[x].begin(); iter != s[x].end(); ++iter) {
        s[y].insert(*iter);
    }
    return fa[x];
}

void Union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (s[fx].size() > s[fy].size()) {
        swap(fx, fy);
    }
    fa[fx] = fy;
    for (set<int>::iterator iter = s[fx].begin(); iter != s[fx].end(); ++iter) {
        s[fy].insert(find(*iter));
    }
}

void work() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    while (q--) {
        scanf("%s", ch);
        if (ch[0] == 'R') {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (z == 1) {
                Union(x, y);
            } else {
                x = find(x), y = find(y);
                s[x].insert(y);
                s[y].insert(x);
            }
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            x = find(x), y = find(y);
            if (x == y) {
                printf("1");
            } else if (s[x].find(y) != s[x].end() || s[y].find(x) != s[y].end()) {
                printf("2");
            } else {
                printf("3");
            }
            printf("\n");
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
