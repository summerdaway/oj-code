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


priority_queue<pair<pair<pair<int, int>, int>, pair<int, int> > > q;
int n, m, p;

void add(int x, int y) {
    int mid = (x + y) >> 1;
    int l = mid - x, r = y - mid;
    if (y - x > 1) {
        q.push(make_pair(make_pair(make_pair(min(l, r), max(l, r)), -mid), make_pair(x, y)));
    }
}

void work() {
    scanf("%d%d%d", &n, &m, &p);
    int l = 0, x;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        add(l, x);
        l = x;
    }
    add(x, n + 1);
    while (p--) {
        pair<pair<pair<int, int>, int>, pair<int, int> > now = q.top();
        q.pop();
        int x = -now.first.second;
        printf("%d\n", x);
        add(now.second.first, x);
        add(x, now.second.second);
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