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

map<string, int> f;
bool v[10111];
int n, ans, Hash[1001111], pp[3111];
string a[10111];
char ch[1001111];
vector<int> e[10111];
map<int, map<string, int> > g;
int MOD = 99997;
queue<int> q;
char st[10];

int hash_fun(string s) {
    int l = s.size();
    int h = 0;
    for (int i = 0; i < l; ++i) {
        h = (h << 8) + s[i];
        h %= MOD;
    }
    return h;
}

void work() {
    pp[0] = 1;
    for (int i = 1; i < 3000; ++i) {
        pp[i] = pp[i-1] * 256 % MOD;
    }
    scanf("%d%s", &n, st);
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        a[i] = (string) ch;
        f[a[i]] = i + 1;
        g[hash_fun(a[i])][a[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        int l = a[i].size();
        //if (l > 2000) continue;
        Hash[l] = 0;
        for (int j = l - 1; j >= 0; --j) {
            Hash[j] = 1LL * a[i][j] * pp[l-1-j] + Hash[j+1];
            Hash[j] %= MOD;
        }
        int h = 0;
        string cur = "";
        for (int j = 0; j < l; ++j) {
            int hh = (1LL * h * pp[l - 1 -j] % MOD + Hash[j+1]) % MOD;
            if (g.find(hh) != g.end()) {
                string s = cur + a[i].substr(j + 1, l);
                if (g[hh].find(s) != g[hh].end()) {
                    e[g[hh][s]-1].push_back(i);
                }
            }
            cur += a[i][j];
            h = ((h<<8) | a[i][j]) % MOD;
        }
    }
    q.push(f[st]);
    v[f[st]] = true;
    while (!q.empty()) {
        int now = q.front();
        ans = max(ans, (int) a[now].size());
        q.pop();
        for (int i = 0; i < e[now].size(); ++i) {
            int j = e[now][i];
            if (!v[j]) {
                v[j] = true;
                q.push(j);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}