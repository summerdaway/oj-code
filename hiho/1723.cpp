#pragma GCC optimize(2)
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

int n, q;
vector<int> a[101111];
long long w[101111];
long long p[101111][70];
bool v[101111][70];

void dfs(int x) {
    for (int i = 0; i < 60; ++i) {
        if ((w[x] >> i) & 1) {
            p[x][i] = w[x];
            v[x][i] = true;
            break;
        }
    }
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        dfs(y);
        for (int j = 0; j < 60; ++j) {
            if (v[y][j]) {
                long long tmp = p[y][j];
                for (int k = 0; k < 60; ++k) {
                    if (((tmp >> k) & 1) && v[x][k]) {
                        tmp ^= p[x][k];
                    }
                }
                if (tmp) {
                    for (int k = 0; k < 60; ++k) {
                        if ((tmp >> k) & 1) {
                            p[x][k] = tmp;
                            v[x][k] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void work() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &w[i]);
    }
    dfs(1);
    while (q--) {
        int x;
        scanf("%d", &x);
        int ct = 0;
        for (int i = 0; i < 60; ++i) {
            ct += v[x][i];
        }
        printf("%lld\n", 1LL << ct);
    }

}


int main() {
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}