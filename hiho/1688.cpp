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

char s1[101111], s2[101111];
pair<char, int> a[101111], b[101111];
int n, x1, x2, ans;

void work() {
    scanf("%s%s", s1, s2);
    n = strlen(s1);
    for (int i = 0; i < n; ++i) {
        if (s1[i] != '_') {
            a[x1].first = s1[i], a[x1++].second = i;
        }
        if (s2[i] != '_') {
            b[x2].first = s2[i], b[x2++].second = i;
        }
    }
    if (x1 != x2) {
        printf("-1\n");
        return;
    }
    n = x1;
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            printf("-1\n");
            return;
        }
        if (a[i].first == 'R'){
            if (a[i].second > b[i].second) {
                printf("-1\n");
                return;
            } else {
                ans += b[i].second - a[i].second;
            }
        } else {
            if (a[i].second < b[i].second) {
                printf("-1\n");
                return;
            } else {
                ans += a[i].second - b[i].second;
            }
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