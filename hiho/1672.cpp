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

int n, x, y, ans, m;
pair<int, int> a[101111], b[201111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
        b[m].first = a[i].first;
        b[m++].second = i*2;
        b[m].first = a[i].second;
        b[m++].second = i*2+1;
    }
    sort(b, b + m);
    x = y = -1;
    for (int i = 0; i < m; ++i) {
        if (b[i].second & 1) {
            int t = b[i].second >> 1;
            if (y != -1) {
                if (y < a[t].first) {
                    ans += 2;
                    y = a[t].second;
                    x = y - 1;
                } else if (x < a[t].first) {
                    x = y;
                    y = a[t].second;
                    ans++;
                } else {
                    continue;
                }
            } else if (x != -1) {
                if (x < a[t].first) {
                    ans ++;
                    x = y;
                    y = a[t].second;
                }
            } else {
                y = b[i].first;
                x = b[i].first - 1;
                ans += 2;
            }
        }
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
