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

int n, m, a[2111][2111], L[2111], R[2111], s[2111], q[2111], r, ans;
char ch[2111];

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        for (int j = 0; j < m; ++j) {
            a[i][j] = ch[j] == '1';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i && a[i][j] != a[i-1][j]) {
                s[j] = s[j] + 1;
            } else {
                s[j] = 1;
            }
        }
        r = 0;
        int prv;
        for (int j = 0; j < m; ++j) {
            if (j == 0 || a[i][j] == a[i][j-1]) {
                r = 0;
                L[j] = 1;
                prv = j - 1;
            } else {
                while (r && s[q[r-1]] >= s[j]) {
                    r--;
                }
                if (r == 0) {
                    L[j] = j - prv;
                } else {
                    L[j] = j - q[r-1];
                }
                q[r++] = j;
            }
        }
        r = 0;
        for (int j = m - 1; j >= 0; --j) {
            if (j == m - 1 || a[i][j+1] == a[i][j]) {
                r = 0;
                prv = j + 1; 
                R[j] = 1;
            } else {
                while (r && s[q[r-1]] >= s[j]) {
                    r--;
                }
                if (r == 0) {
                    R[j] = prv - j;
                } else {
                    R[j] = q[r-1] - j;
                }
                q[r++] = j;
            }
            ans = max(ans, s[j] * (L[j] + R[j] - 1));
        }
    }
    printf("%d\n", ans);
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