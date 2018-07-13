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

bool v[101111];
int fa[101111], f1[101111], f2[101111], n, depth[101111];
long long ans[101111];
vector<int> a[101111], dn[101111];
set<pair<int, int> > s[101111];

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


void work() {
    scanf("%d", &n);
    n=100000;
    for (int i = 1; i <= n; ++i) {
        f1[i] = f2[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        // scanf("%d%d", &x, &y);
        x = i + 1, y = x - 2;
        if (!y) ++y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    int maxd = 0;
    while (!q.empty()) {
        int x = q.front();
        maxd = depth[x];
        dn[depth[x]].push_back(x);
        q.pop();
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            if (y != fa[x]) {
                q.push(y);
                depth[y] = depth[x] + 1;
                fa[y] = x;
            }
        }
    }

    for (int i = maxd; i >= 0; --i) {
        for (int j = 0; j < dn[i].size(); ++j) {
            int x = dn[i][j];
            int mx = 0, yy = -1;
            for (int k = 0; k < a[x].size(); ++k) {
                int y = a[x][k];
                if (fa[y] != x) {
                    continue;
                }
                // if (s[p[y]].size() > mx) {
                //     mx = s[p[y]].size();
                //     yy = p[y];
                // }
                if (s[y].size() > mx) {
                    mx = s[y].size();
                    yy = y;
                }
            }
            // printf("yy=%d\n", yy);
            s[x].insert(make_pair(x, x));
            a[x].push_back(x);
            if (yy == -1) {
                a[x].push_back(n+2);
                yy = n + 2;
                s[yy].clear();
                ans[yy] = 1LL*n*(n-1)/2;
            }

            ans[x] = ans[yy];
            // printf("x=%d ans=%lld\n", x, ans[x]);

            for (int i = 0; i < a[x].size(); ++i) {
                int y = a[x][i];
                if ((y == x || fa[y] == x) && y != yy) {
                    // printf("insert %d\n", y);
                    // for (set<int>::iterator iter = s[p[y]].begin(); iter != s[p[y]].end(); ++iter) {
                    for (set<pair<int, int> >::iterator iter = s[y].begin(); iter != s[y].end(); ++iter) {
                        int l = iter->first, r = iter->second;

                        set<pair<int, int> >::iterator iter1 = s[yy].lower_bound(make_pair(l, r));
                        int r1 = 0, l2 = n + 1;
                        if (iter1 != s[yy].end()) {
                            l2 = iter1->first;
                        }
                        if (iter1 != s[yy].begin()) {
                            --iter1;
                            r1 = iter1->second;
                        }
                        // printf("l=%d r=%d \n", l, r);

                        int tmp = r-l+1;
                        // ans[x] += -1LL*(l-r1-1)*tmp - 1LL*(l2-r-1)*tmp + 1LL*tmp*(tmp-1)/2 - 1LL*(l-r1-1)*(l2-r-1);
                        ans[x] -= 1LL*(l2-r1-1)*(l2-r1-2)/2;

                        if (r1 > 0 && r1 == l - 1) {
                            // ans[x] += 1LL*(r1-find1(r1)+1)*tmp;
                            ans[x] -= 1LL*(r1-find1(r1)+1)*(r1-find1(r1))/2;
                            s[yy].erase(make_pair(find1(r1), r1));
                            Union1(l, r1);
                            Union2(r1, l);
                        } else {
                            ans[x] += 1LL*(l-r1-1)*(l-r1-2)/2;
                        }
                        if (l2 <= n && l2 == r + 1) {
                            // ans[x] += 1LL*(find2(l2)-l2+1)*tmp;
                            ans[x] -= 1LL*(find2(l2)-l2+1)*(find2(l2)-l2)/2;
                            s[yy].erase(make_pair(l2, find2(l2)));
                            Union1(l2, r);
                            Union2(r, l2);
                        } else {
                            ans[x] += 1LL*(l2-r-1)*(l2-r-2)/2;
                        }
                        s[yy].insert(make_pair(find1(l), find2(r)));
                        ans[x] += 1LL*(find2(r)-find1(l)+1)*(find2(r)-find1(l))/2;
                        // printf("ans=%lld\n", ans[x]);
                    }
                } else {
                    continue;
                }
                // printf("intervals:\n");
                // for (set<pair<int, int> >::iterator iter = s[yy].begin(); iter != s[yy].end(); ++iter) {
                //     printf("%d %d\n", iter->first, iter->second);
                // }
            }
            // p[x] = yy;
            // if (p[x] > n) {
            //     s[x] = s[p[x]];
            //     p[x] = x;
            // }
            s[x] = s[yy];
            // printf("x=%d size=%d\n", x, s[x].size());
            // printf("x=%d \n", x);
            // for (set<pair<int, int> >::iterator iter = s[x].begin(); iter != s[x].end(); ++iter) {
            //     printf("%d %d\n", iter->first, iter->second);
            // }
            // printf("\n");
            // printf("x=%d ans=%lld\n", x, ans[x]);
            // printf("\n");
        }
    }

    long long tmp = 0;
    for (int i = 2; i <= n; ++i) {
        // printf("%lld ", ans[i]);
        tmp += ans[i];
    }
    // for (int i = 1; i <= n; ++i) {
    //     printf("i=%d ans=%lld\n", i, ans[i]);
    // }
    printf("%lld\n", 1LL*n*(n-1)*(n-1)/2 - tmp);
}


int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
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


/*
Problem >_{
    一棵编号1~n的树，Tree[L, R]表示覆盖编号在[L, R]的所有点，需要的最少边数，求
    $\sum_{L=1}^n \sum_{R=L}^n Tree[L, R]$
    $n\le 100000$
}_<

Solution >_{
    $n^2$暴力：枚举点 i 作为树的根，dfs(i)，然后枚举 [i, n]，对于当前 j ，将 j, fa[j], fa[fa[j]]… 到根 i 的一路上的边加入，碰到加过的就停止

    nlogn：n个点形成的区间个数为 n(n-1)/2，树共有 n-1 条边，如果所有区间都用到所有的边，总共有n(n-1)^2/2条边。
    任选一个点作为根建树，考虑 (i, fa[i]) 这条边，有多少个区间不选它。以 i 为根的子树的编号形成了很多个区间 [l_1, r_1], [l_2, r_2] …这些区间内部的区间不需要用到 (i, fa[i])，并且这些区间的间隙 ([r_1+1, l2-1]…) 也不需要用到 (i, fa[i])。
    那么对一个点 i，记录以 i 为根的子树编号的区间集合 s ，和用不到 (i, fa[i]) 这条边的区间个数 ans[i]
    每次对点 i，选它最重的儿子不动，把其他儿子的集合合并到最重的儿子上，合并时，当前要插入的区间 [l, r] 将原来集合里的某个间隙切开了
    1. 先减掉这个间隙的区间个数
    2. 判断是否可以和左边、右边的区间接上，如果能接上，要删除原来的区间，并减掉这段的区间个数，否则加上新形成的间隙的区间个数
    3. 加上当前区间的区间个数
    注意
    1. 对点 i 合并时，需要将 i 也合并进去，可以在 i 的邻接表里加入 i，s[i]={i}，将s[i]当成儿子合并，可以简化代码
    2. 集合里记录区间，而不是区间端点，更不容易出问题
    3. 可以bfs就不要dfs，会爆堆栈
    4. 更新答案的时候先想好，不然很容错
}_<