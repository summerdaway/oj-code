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

int n, m, w[101111], fa[101111], root;

int find(int x) {
    return fa[x] == root || w[fa[x]] >= m ? fa[x] : fa[x] = find(fa[x]);
}



void work() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &fa[i]);
        if (fa[i] == 0) {
            root = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != root) find(i);
        if (w[i] >= m) {
            printf("%d", fa[i]);
        } else {
            printf("-1");
        }
        printf(i == n ? "\n" : " ");
    }

}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}