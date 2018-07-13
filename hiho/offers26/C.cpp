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

int f1[101111], f2[101111], n, K, ans, a[101111];
bool v[101111];

int find1(int x) {
    return x == f1[x] ? x : f1[x] = find1(f1[x]);
}

int find2(int x) {
    return x == f2[x] ? x : f2[x] = find2(f2[x]);
}

void Union1(int x, int y) { 
    x = find1(x), y = find1(y);
    if (x < y) swap(x, y);
    f1[x] = y;
}

void Union2(int x, int y) {
    x = find2(x), y = find2(y);
    if (x > y) swap(x, y);
    f2[x] = y;
}



void work() {

    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    if (K == n) {
        printf("0\n");
        return;
    }

    for (int i = 0; i <= n + 1; ++i) {
        f1[i] = f2[i] = i;
    }

    ans = -1;
    for (int i = n; i >= 1; --i) {
        int x = a[i];
        if (x-1-find1(x-1) == K) ans = i;
        if (find2(x+1)-x-1 == K) ans = i;
        Union1(x, x - 1);
        Union2(x, x + 1);

    }
    printf("%d\n", ans);

}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
