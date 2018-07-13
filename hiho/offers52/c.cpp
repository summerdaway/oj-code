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
using namespace std;

double f[101111], g[101111];
int n, a[101111], fa[101111];
vector<int> b[101111];
long long ans;

void dfs(int x){
    f[x] = a[x], g[x] = 0;
    for (int i = 0; i < b[x].size(); ++i){
        int y = b[x][i];
        if (fa[y] == x){
            dfs(y);
            f[x] += max(f[y] - 1.0*a[y]/2, g[y]);
            g[x] += max(f[y], g[y]);
        }
    }
}


void work() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        b[x].push_back(y);
        fa[y] = x;
    }
    for (int i = 1; i <= n; ++i){
        if (fa[i] == 0){
            dfs(i);
            printf("%.1lf\n", max(f[i], g[i]));
        }
    }

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
