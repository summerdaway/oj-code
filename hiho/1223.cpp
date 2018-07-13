
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

int n, m, ans, cur;
char b[20], c[20];
pair<int, int> a[10111];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%s%s%d", c, b, &x);
        if (b[0] == '>') {
            if (b[1] == '=') {
                a[m].first = x*2;
            } else {
                a[m].first = x*2+1;
            }
            a[m++].second = 0;
        } else if (b[0] == '=') {
            a[m].first = x*2;
            a[m++].second = 0;
            a[m].first = x*2;
            a[m++].second = 1;
        } else if (b[0] == '<') {
            if (b[1] == '=') {
                a[m].first = x*2;
            } else {
                a[m].first = x*2-1;
            }
            a[m++].second = 1;
        }
        if (b[0] == '<') cur++;
    }
    ans = max(ans, cur);
    sort(a, a + m);
    for (int i = 0; i < m; ++i) {
        if (a[i].second == 0) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur--;
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
