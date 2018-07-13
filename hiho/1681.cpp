#prag\
ma GCC optimize ("O2") 
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

int n, m;
char ch[101111];
int Len[20], s[20][101111];
const long long MOD = 100000000000000000LL + 7;
int l, r;
long long p[101111];
long long g[11][101111];
int ng[11], st[11];

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        int len = Len[i];
        ng[i] = 0;
        if (len < x) continue;
        long long h = 0;
        for (int j = 0; j < x; ++j) {
            h *= 26;
            h += s[i][j];
            h %= MOD;
        }
        g[i][ng[i]++] = h;
        for (int j = x; j < len; ++j) {
            h *= 26;
            h += s[i][j];
            h -= p[x] * s[i][j-x];
            h = (h%MOD+MOD)%MOD;
            g[i][ng[i]++] = h;
        }
        sort(g[i], g[i] + ng[i]);
    }
    memset(st, 0, sizeof(st));
    long long prv = -1, ct = 0;
    while (true) {
        long long mn = MOD, x = -1;
        for (int i = 0; i < n; ++i) {
            if (st[i] == ng[i]) continue;
            if (g[i][st[i]] < mn) {
                mn = g[i][st[i]];
                x = i;
            }
        }
        if (x == -1) break;
        while (st[x] < ng[x] && g[x][st[x]] == mn) st[x]++;
        if (mn == prv) ct++;
        else {
            prv = mn;
            ct = 1;
        }
        if (ct >= m) return true;
    }
    if (ct >= m) return true;
    return false;
}


void work() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        Len[i] = strlen(ch);
        for (int j = 0; j < Len[i]; ++j) {
            s[i][j] = ch[j] - 'a';
        }
    }
    l = 0;
    r = 100001;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);


}

int main() {
    srand(time(0));
    p[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        p[i] = p[i-1]*26%MOD;
    }

    //freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
