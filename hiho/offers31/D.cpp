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

int n, a[511][511], b[511], ct[511][511], m;
bool vv[511][511], v[511];

void work() {
    scanf("%d", &n);
    printf("%d\n", n);
    if (n == 1) {
        printf("1\n1\n");
        return;
    } else if (n == 2) {
        printf("1\n1 2\n");
        return;
    } else if (n == 3) {
        printf("2\n");
        printf("1 2 3\n");
        printf("1 3 2\n");
        return;
    }
    printf("%d\n", (n+1)/2);
    //3 2 1 
    //2 3 1
    a[0][0] = 3;
    a[0][1] = 2;
    a[0][2] = 1;
    a[1][0] = 2;
    a[1][1] = 3;
    a[1][2] = 1;

    m = 2;
    for (int i = 4; i <= n; ++i) {
        if (i & 1) {
            a[m][i-1] = a[m-1][i-2];
            int tmp = a[m][i-1];
            int ct = i-2;
            memset(v, 0, sizeof(v));
            v[tmp] = true;
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < i-2; ++k) {
                    int x = a[j][k], y = a[j][k+1];
                    if (x == tmp || y == tmp) {
                        for (int p = i-1; p > k+1; --p) {
                            a[j][p] = a[j][p-1];
                        }
                        a[j][k+1] = i;
                        if (y == tmp) {
                            swap(x, y);
                        }
                        a[m][ct--] = y;
                        tmp = y;
                        v[tmp] = true;
                        break;
                    }
                }
            }
            a[m][0] = i;
            for (int j = 1; j < i; ++j) {
                if (!v[j]) {
                    a[m][1] = j;
                    break;
                }
            }
            m++;
        } else {
            memset(ct, 0, sizeof(ct));
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < i-2; ++k) {
                    int x = a[j][k], y = a[j][k+1];
                    ct[x][y] += 1;
                    ct[y][x] += 1;
                }
            }
            memset(vv, 0, sizeof(vv));
            int j = m - 1;
            for (int k = 0; k < i - 2; ++k) {
                int x = a[j][k], y = a[j][k+1];
                if (ct[x][y] > 1) {
                    for (int tmp = i-1; tmp > k + 1; tmp--) {
                        a[j][tmp] = a[j][tmp-1];
                    }
                    a[j][k+1] = i;
                    vv[x][y] = vv[y][x] = true;
                    break;
                }
            }
            a[m-2][i-1] = i;
            for (j -= 2; j >= 0; --j) {
                for (int k = 0; k < i - 2; ++k) {
                    int x = a[j][k], y = a[j][k+1];
                    if (ct[x][y] > 1 && !vv[x][y]) {
                        for (int tmp = i-1; tmp > k + 1; tmp--) {
                            a[j][tmp] = a[j][tmp-1];
                        }
                        a[j][k+1] = i;
                        vv[x][y] = vv[y][x] = true;
                        break;
                    }
                }
            }
            printf("here\n");
            //a[0][i-1] = a[0][i-2], a[0][i-2] = i;
        }
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < i; ++k) {
                printf("%d ", a[j][k]);
            }
            printf("\n");
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
