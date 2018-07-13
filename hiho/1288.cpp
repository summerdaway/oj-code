
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

int a[1111];

void work() {
    int n, w, h, p;
    scanf("%d%d%d%d", &n, &p, &w, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = min(w, h); i; --i) {
        int lines = 0;
        for (int j = 0; j < n; ++j) {
            lines += a[j] / (w/i);
            lines += (a[j] % (w/i)) != 0;
        }
        int pages = lines / (h/i);
        pages += (lines % (h/i)) != 0;
        if (pages <= p) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
