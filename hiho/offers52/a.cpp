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

const int maxn = 101111;

bool v[maxn];
int fa[maxn], f1[maxn], f2[maxn], n;
long long ans[maxn];
vector<int> a[101111];
set<int> s[101111];

int find1(int x) {
    return f1[x] == x ? x : f1[x] = find1(f1[x]);
}

int find2(int x) {
    return f2[x] == x ? x : f2[x] = find2(f2[x]);
}

void Union1(int x, int y) {
    x = find1(x), y = find1(y);
    f1[x] = y;
}

void Union2(int x, int y) {
    x = find2(x), y = find2(y);
    f2[x] = y;
}

void dfs(int x) {
    v[x] = true;
    int mx = 0, yy = -1;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if (!v[y]) {
            fa[y] = x;
            dfs(y);
            if (s[y].size() > mx) {
                mx = s[y].size();
                yy = y;
            }
        }
    }
    s[x].insert(x);
    a[x].push_back(x);
    if (yy == -1) {
        a[x].push_back(n+2);
        yy = n+2;
        s[yy].clear();
        ans[yy] = 1LL*n*(n-1)/2;
    }
    // printf("yy=%d\n", yy);
    ans[x] = ans[yy];
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if ((y == x || fa[y] == x) && y != yy) {
            // printf("x=%d y=%d\n", x, y);
            vector<int> arr;
            for (set<int>::iterator iter = s[y].begin(); iter != s[y].end(); ++iter) {
                if (find1(*iter) == *iter) {
                    arr.push_back(*iter);
                }
            }
            for (int k = 0; k < arr.size(); k ++) {
                int t = arr[k];
                int l = find1(t), r = find2(t);
                set<int>::iterator iter1 = s[yy].lower_bound(t);
                int r1 = 0, l2 = n + 1;
                if (iter1 != s[yy].end()) {
                    l2 = *iter1;
                }
                if (iter1 != s[yy].begin()) {
                    --iter1;
                    r1 = *iter1;
                }

                int tmp = r-l+1;
                ans[x] += -1LL*(l-r1-1)*tmp - 1LL*(l2-r-1)*tmp + 1LL*tmp*(tmp-1)/2 - 1LL*(l-r1-1)*(l2-r-1);

                if (r1 > 0 && r1 == l - 1) {
                    ans[x] += 1LL*(r1-find1(r1)+1)*tmp;
                    Union1(l, r1);
                    Union2(r1, l);
                    s[yy].erase(s[yy].find(r1));
                }
                if (l2 <= n && l2 == r + 1) {
                    ans[x] += 1LL*(find2(l2)-l2+1)*tmp;
                    Union1(l2, r);
                    Union2(r, l2);
                    s[yy].erase(s[yy].find(l2));
                }
                s[yy].insert(find1(t));
                s[yy].insert(find2(t));
            }
        }
    }
    s[x] = s[yy];

}


void work() {
    scanf("%d", &n);
    n = 1000;
    for (int i = 1; i <= n; ++i) {
        f1[i] = f2[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        //scanf("%d%d", &x, &y);
        x = i; y = i + 1;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    long long tmp = 0;
    for (int i = 2; i <= n; ++i) {
        tmp += ans[i];
    }
    printf("%lld\n", 1LL*n*(n-1)*(n-1)/2 - tmp);
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
