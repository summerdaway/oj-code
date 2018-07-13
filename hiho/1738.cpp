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

int n, x, H, m, a[101111], b[101111];
set<pair<int, int> > s;

void work() {
    scanf("%d%d%d%d", &n, &x, &H, &m);
    for (int i = 1; i <= n; ++i) {
        if (i == x) {
            b[i] = H;
        } else {
            b[i] = H;
        }
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        if (s.find(make_pair(x, y)) != s.end() || x == y) continue;
        s.insert(make_pair(x, y));
        a[x+1] -= 1;
        a[y] += 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        printf("%d\n", b[i] + sum);
    }
}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
