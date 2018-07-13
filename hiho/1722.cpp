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

set<pair<int, int> > p;
priority_queue<pair<int, int> > q;
int n, m, ans, b[201111];

void work() {
    scanf("%d%d", &n, &m);
    int a[n+10][m+10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
        sort(a[i], a[i] + m);
    }
    for (int i = 0; i < n; ++i) {
        q.push(make_pair(-a[i][0], i));
        p.insert(make_pair(a[i][0], i));
    }
    ans = 100000000;
    while (1) {
        pair<int, int> now = q.top();
        int x = -now.first, y = now.second;
        q.pop();
        set<pair<int, int> >::iterator iter = p.end();
        --iter;
        ans = min(ans, iter->first - x);
        b[y]++;
        if (b[y] == m) break;
        q.push(make_pair(-a[y][b[y]], y));
        iter = p.find(make_pair(x, y));
        p.erase(iter);
        p.insert(make_pair(a[y][b[y]], y));
    }
    printf("%d\n", ans);


}


int main() {
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}