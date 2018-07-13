#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

char p[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int f[] = {1, 5, 10, 50, 100, 500, 1000};

map<string, int> g;
struct Node {
    string x, y;
} s[101111];
int n;
int m = 7;

int get1(string t, int l, int r) {
    if (l > r) return 0;
    if (l == r) {
        for (int i = 0; i < m; ++i) {
            if (t[l] == p[i]) {
                return f[i];
            }
        }
    }
    for (int j = m - 1; j >= 0; --j) {
        for (int i = l; i <= r; ++i) {
            if (t[i] == p[j]) {
                return -get1(t, l, i - 1) + get1(t, i + 1, r) + f[j];
            }
        }
    }
}

bool cmp(const Node &a, const Node &b) {
    if (a.x < b.x) return true;
    if (a.x > b.x) return false;
    return g[a.y] < g[b.y];
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].x >> s[i].y;
        g[s[i].y] = get1(s[i].y, 0, s[i].y.size() - 1);
        //printf("%d\n", g[s[i].y]);

    }

    sort(s, s + n, cmp);

    for (int i = 0; i < n; ++i) {
        printf("%s %s\n", s[i].x.c_str(), s[i].y.c_str());
    }



}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}