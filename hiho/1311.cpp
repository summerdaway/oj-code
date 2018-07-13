#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int b[1111111], n, m, ans[1111111];
char a[111];

int check() {
    for (int i = 0; i < n; ++i) {
        if (b[i] != 0) {
            return b[i] == 5 ? 0 : 1;
        }
    }
    return -1;
}

void work() {
    scanf("%s", a);

    n = strlen(a);
    memset(b, 0, sizeof(b));
    for (int i = 2; i < n; ++i) {
        b[n-i-1] = a[i] - '0';
    }
    n -= 2;
    m = 0;
    while (true) {
        int t = 0;
        if ((t = check()) == 1) {
            printf("NO\n");
            return;
        } else if (t == -1 ) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            b[i] *= 2;
        }
        for (int i = 0; i < n; ++i) {
            b[i+1] += b[i] / 10;
            b[i] %= 10;
        }
        if (b[n]) {
            ans[m] = 1;
        } else {
            ans[m] = 0;
        }
        b[n] = 0;
        m++;
    }
    printf("0.");
    for (int i = 0; i < m; ++i) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}