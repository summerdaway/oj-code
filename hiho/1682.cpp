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

int n, ans[111][111];
char a[111][111];
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};


void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 9; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || y < 0 || x >= n || y >= n) continue;
                ans[i][j] += a[x][y] == '*';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '.') printf("%d", ans[i][j]);
            else printf("*");
        }
        printf("\n");
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