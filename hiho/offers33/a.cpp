#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, a[222][222], b[222], ans;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j] += a[i][j];
        }
    }
    sort(b, b + n);
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] < 0 && b[i+1] < 0) {
            b[i] = -b[i];
            b[i+1] = -b[i+1];
            ++i;
        } else if (b[i] >= 0) break;
        else {
            if (-b[i] > b[i+1]) {
                b[i] = -b[i];
                b[i+1] = -b[i+1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans += b[i];
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}