#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

double f[10][6][8], ans, a[10][8], p[10][6][8];
int n, L, m, b[10], status[2][2][2];
int last_b[10];

pair<int, int> calc_status(int p1, int p2, int p3) {
    if (p1 == 0) {
        return make_pair(status[1][p2][p3], 0);
    } else {
        if (p2 == 0) {
            return make_pair(status[1][1][p3], 0);
        } else {
            return make_pair(status[1][1][1], p3);
        }
    }
}

void work() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                status[i][j][k] = (k<<2) + (j<<1) + i;
            }
        }
    }

    scanf("%d%d%d", &n, &L, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 7; ++j) {
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        b[i] = i;
    }

    memset(last_b, -1, sizeof(last_b));

    do {
        bool flag = true;
        for (int i = 0; i < L; i ++) {
            if (b[i] != last_b[i]) {
                flag = false;
            }
        }
        if (!flag) {
            memset(f, 0, sizeof(f));
            memset(p, 0, sizeof(p));
            p[0][0][0] = 1;
            for (int i = 0; i < L; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < 8; ++k) {
                        if (p[i][j][k] == 0) continue;
                        int p1 = (k&1), p2 = ((k>>1)&1), p3 = ((k>>2)&1);
                        int c = b[i];
                        f[i+1][j][status[0][0][0]] += (f[i][j][k] + (p1+p2+p3+1) * p[i][j][k]) * a[c][0];
                        p[i+1][j][status[0][0][0]] += p[i][j][k] * a[c][0];
                        f[i+1][j][status[0][0][1]] += (f[i][j][k] + (p1+p2+p3) * p[i][j][k])  * a[c][1];
                        p[i+1][j][status[0][0][1]] += p[i][j][k] * a[c][1];
                        f[i+1][j][status[0][1][p1]] += (f[i][j][k] + (p2+p3) * p[i][j][k])  * a[c][2];
                        p[i+1][j][status[0][1][p1]] += p[i][j][k] * a[c][2];
                        f[i+1][j][status[1][p1][p2]] += (f[i][j][k] + (p3) * p[i][j][k])  * a[c][3];
                        p[i+1][j][status[1][p1][p2]] += p[i][j][k] * a[c][3];
                        f[i+1][j+1][status[p1][p2][p3]] += f[i][j][k] * a[c][4];
                        p[i+1][j+1][status[p1][p2][p3]] += p[i][j][k] * a[c][4];
                        f[i+1][j+1][status[0][p1][p2]] += (f[i][j][k] + (p3) * p[i][j][k])  * a[c][5];
                        p[i+1][j+1][status[0][p1][p2]] += p[i][j][k] * a[c][5];
                        pair<int, int> tmp = calc_status(p1, p2, p3);
                        f[i+1][j][tmp.first] += (f[i][j][k] + (tmp.second) * p[i][j][k])  * a[c][6];
                        p[i+1][j][tmp.first] += p[i][j][k] * a[c][6];
                    }
                }
            }
            double sum = 0;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k < 8; ++k) {
                    sum += f[L][j][k];
                }
            }
            for (int i = 0; i < L; ++i) {
                for (int k = 0; k < 8; ++k) {
                    sum += f[i][m][k];
                }
            }

            ans = max(ans, sum);
        }
        memcpy(last_b, b, sizeof(b));
    } while (next_permutation(b, b + n));

    printf("%lf\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    int t = clock();
#endif
    int TestCase = 1;
    // scanf("%d", &TestCase);
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
    棒球，场上有4个垒，1、2、3、本垒。每人打了一棒可能有7种情况：
    1. 本垒打：所有垒清空，得分增加垒上人数+1（走4步）
    2. 三垒打：打手上三垒，得分增加原垒上人数（走3步）
    3. 二垒打：打手上二垒，一垒若有人则上三垒，得分增加原二三垒人数（走2步）
    4. 安打：打手上一垒，其他人进一垒（走1步）
    5. 三振：打手出局
    6. 牺牲打：打手出局，其他人进一垒（其他人走1步）
    7. 保送：打手上一垒，从一垒开始，若有人，把人往下一垒推

    现在总共有$n$个人，给出每个人打出7种情况的概率。最多可以打$L$次，出局人数最多为$m$人，安排$n$个人的击打顺序，使得得分的期望最大

    $1\le m\le 5$, $1\le L\le n\le9$
}_<

Solution >_{
    枚举前$L$棒由谁来打，假设顺序是$b_0,...,b_{L-1}$，$f(i, j, k)$表示前$i$个人，出局了$j$个，垒上状态为$k$的期望得分，$p(i, j, k)$表示对应状态的概率，$a_{ij}$是第$i$个人打出第$j$种情况的概率，那么有
    <center>$p(i, j, k) * a_{b[i],0-7} -> p(i+1, newj, newk)$</center>
    <center>$(f(i, j, k) + score(k, 0-7)*p(i, j, k)) * a_{b[i],0-7} -> f(i+1, newj, newk)$</center>
    其中newj和newk根据情况计算。
    最后对$f$求和，$ans=\sum_{j\le m, k<8} f(L, j, k) + \sum_{i<L, k<8} f(i, m, k)$。注意后面这一项是还没有打到$L$次，出局人数就达到了$m$。
}_<
*/
