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

int n, fa[10011], a[10011], b[10011], d[10111];
vector<int> c[10011];
char ch[20];
string ans;
struct Node
{
    int l, r, x, mx, mn;
} T[10111];
int p;

int find(int x) {
    return x == d[x] ? x : d[x] = find(d[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    d[x] = y;
}

bool dfs(int x, int &node) {
    if (x == 0) {
        ans += "()";
        return false;
    }
    if (node == 0) {
        node = ++p;
        T[node].x = x;
        T[node].l = T[node].r = 0;
    }
    ans += '(';
    sprintf(ch, "%d", x);
    ans += (string) ch;

    bool ret = false;
    for (int i = 0; i < c[x].size(); ++i) {
        if (c[x][i] < x) {
            if (T[node].l) {
                return true;
            } else {
                T[node].l = c[x][i];
            }
        } else {
            if (T[node].r) {
                return true;
            } else {
                T[node].r = c[x][i];
            }
        }
    }
    int l = T[node].l, r = T[node].r;
    T[node].l = T[node].r = 0;
    ret = dfs(l, T[node].l) || dfs(r, T[node].r);

    if (ret) return true;

    if (T[T[node].l].mx > T[node].x) return true;
    if (T[T[node].r].mn < T[node].x) return true;
    T[node].mn = min(T[T[node].l].mn, min(T[T[node].r].mn, T[node].x));
    T[node].mx = max(T[T[node].l].mx, max(T[T[node].r].mx, T[node].x));
    ans += ')';
    return ret;
}

void work() {
    scanf("%d", &n);
    p = 1;
    for (int i = 1; i <= n; ++i) {
        c[i].clear();
    }
    ans = "";
    memset(fa, 0, sizeof(fa));
    T[0].mn = 10111, T[0].mx = 0;

    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        fa[b[i]] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        if (find(a[i]) == find(b[i])) {
            printf("ERROR1\n");
            return;
        }
        Union(a[i], b[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (fa[b[i]] != a[i]) {
            printf("ERROR1\n");
            return;
        }
    }
    for (int i = 1; i < n; ++i) {
        fa[b[i]] = a[i];
        c[a[i]].push_back(b[i]);
        if (c[a[i]].size() > 2) {
            printf("ERROR2\n");
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(c[i].begin(), c[i].end());
    }

    for (int i = 1; i <= n; ++i) {
        if (fa[i] == 0) {
            int x = 0;
            if (dfs(i, x)) {
                printf("ERROR3\n");
                return;
            } else {
                printf("%s\n", ans.c_str());
            }
        }
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}