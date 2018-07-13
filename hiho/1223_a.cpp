
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

int n, a[55], ans;
char b[55][10], c[10];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%s%s%d", c, b[i], &a[i]);
        a[i] <<= 1;
    }
    for (int i = -1; i <= 2100; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j][0] == '>') {
                x += i > a[j];
            } else if (b[j][0] == '<') {
                x += i < a[j];
            } else if (b[j][0] == '>' && b[j][1] == '=' ){
                x += i == a[j];
            }
        }
        ans = max(ans, x);
    }
    printf("%d\n", ans);
}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
