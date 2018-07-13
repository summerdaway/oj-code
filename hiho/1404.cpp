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


bool ans[1011];
char a[20][20];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void work() {
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < 15; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (a[i][j] == '.') continue;
            char c = a[i][j];
            int l;
            for (int dr = 0; dr < 8; ++dr) {
                l = 0;
                for (int k = 0; k < 15; ++k) {
                    int x = i + dx[dr]*k, y = j + dy[dr]*k;
                    if (x < 0 || y < 0 || x > 14 || y > 14 || a[x][y] != c) break;
                    l++;
                }
                if (l > 4) break;
            }
            if (l > 4) {
                ans[c] = true;
            }
        }
    }
    if (ans['W'] and ans['B']) printf("Both");
    else if (ans['W']) printf("White");
    else if (ans['B']) printf("Black");
    else printf("None");
    printf("\n"); 

}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
