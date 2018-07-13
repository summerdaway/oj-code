#include <map>
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
#include <set>
using namespace std;

int m, n;
vector<int> a[10111];
string c[10111];
map<string, int> f;
char root[30], ch1[30], ch2[30], ch3[30];
bool b[10111], v[10111];

void dfs(int x) {
    if (x != 1 && !b[x]) {
        printf("%s\n", c[x].c_str());
    }
    v[x] = true;
    for (int i = 0; i < a[x].size(); ++i) {
        if (!v[a[x][i]]) dfs(a[x][i]);
    }
}


void work() {
    scanf("%d", &m);
    scanf("%s", root);
    f[root] = ++n;
    c[1] = root;
    while (m--) {
        scanf("%s%s", ch1, ch2);
        if (ch1[0] == 'b') {
            scanf("%s", ch3);
            if (f.find(ch2) == f.end()) {
                f[ch2] = ++n;
                c[n] = ch2;
            }
            if (f.find(ch3) == f.end()) {
                f[ch3] = ++n;
                c[n] = ch3;
            }
            int x = f[ch2], y = f[ch3];
            a[x].push_back(y);
        } else {
            b[f[ch2]] = 1;
        }
    }
    dfs(f[root]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = clock();
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
