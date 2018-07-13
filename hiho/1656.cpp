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

map<pair<pair<long long,long long>,pair<int,int> >, int> f;
set<pair<pair<long long,long long>,pair<int,int> > > q;
pair<pair<long long,long long>,pair<int,int> > ans[51111];
int n, m, v[51111];
char a[51111][11], s1[11], s2[11];

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", a[i], &v[i]);
    }
    for (int k = 0; k < m; ++k) {
        scanf("%s%s", s1, s2);
        long long x, y;
        x = y = 0;
        int l1 = strlen(s1);
        for (int i = 0; i < l1; ++i) {
            x *= 26;
            x += s1[i] - 'a';
        }
        int l2 = strlen(s2);
        for (int i = l2-1; i >= 0; --i) {
            y *= 26;
            y += s2[i] - 'a';
        }
        q.insert(make_pair(make_pair(x, y), make_pair(l1, l2)));
        ans[k] = make_pair(make_pair(x, y), make_pair(l1, l2));
    }
    for (int k = 0; k < n; ++k) {
        int len = strlen(a[k]);
        long long x, y;
        x = y = 0;
        for (int i = 0; i < len; ++i) {
            x *= 26;
            x += a[k][i] - 'a';
            y = 0;
            for (int j = len-1; j >= 0; --j) {
                y *= 26;
                y += a[k][j] - 'a';
                if (q.find(make_pair(make_pair(x, y), make_pair(i+1, len-j))) != q.end()) {
                    f[make_pair(make_pair(x, y), make_pair(i+1, len-j))] = max(f[make_pair(make_pair(x, y), make_pair(i+1, len-j))], v[k]);
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (f.find(ans[i]) == f.end()) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", f[ans[i]]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
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
