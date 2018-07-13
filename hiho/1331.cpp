
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int f[50][2], n, m, a[50];

void work() {
    scanf("%d", &m);
    while (m) {
        a[n++] = m & 1;
        m >>= 1;
    }
    f[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        f[i][0] = f[i+1][0];
        f[i][1] = f[i+1][1];
        if (a[i] == 0) {
            f[i][0] += f[i+1][1];
        } else {
            f[i][1] += f[i+1][0];
        }
    }
    printf("%d\n", f[0][0]);


}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    // scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
