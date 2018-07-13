#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 101111

int n, m;
vector<int> a[maxn];
int height[maxn], f[maxn][30];

void dfs(int x, int h) {
    height[x] = h;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (height[y] == 0) {
            f[y][0] = x;
            dfs(y, h + 1);
        }
    }
}

void clear() {
    memset(height, 0, sizeof(height));
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= n; ++i) {
        a[i].clear();
    }

}

void prep() {
    for (int i = 0; i < 20; ++i) {
        for (int x = 1; x <= n; ++x) {
            f[x][i+1] = f[f[x][i]][i];
        }
    }
}

int up(int x, int h) {
    if (h == 0) return x;
    for (int i = 0; i < 20; ++i) {
        if ((h >> i) & 1) {
            x = f[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    int h1 = height[x], h2 = height[y];
    if (h1 > h2) {
        x = up(x, h1-h2);
    } else {
        y = up(y, h2-h1);
    }

    for (int i = 20; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i], y = f[y][i];
        }
    }

    return x == y ? x : f[x][0];
}

void work() {

    scanf("%d%d", &n, &m);

    clear();

    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);

    prep();

    while (m--) {
        int X1, Y1, X2, Y2;
        scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
        if (X1 == X2 || X1 == Y2 || Y1 == X2 || Y1 == Y2) {
            printf("YES\n");
            continue;
        }
        int A = lca(X1, Y1);
        int B = lca(X2, Y2);
        if (A == B) {
            printf("YES\n");
            continue;
        }
        int C = lca(A, B);
        if (C != A && C != B) {
            printf("NO\n");
            continue;
        }

        if (C == A && (lca(B, X1) == B || lca(B, Y1) == B)) {
            printf("YES\n");
            continue;
        }
        if (C == B && (lca(A, X2) == A || lca(A, Y2) == A)) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
}

int main() {
    string s = "12345";
    printf("sub=%saa\n", s.substr(5, 5).c_str());
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }

}