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

struct node {
    int len;
    vector<int> b;
    string s;
} a[101111];
int n, ans;
string s;

bool cmp(const node &x, const node &y) {
    if (x.len < y.len) return true;
    if (x.len > y.len) return false;
    for (int i = 0; i < x.len - 1; ++i) {
        if (x.b[i] < y.b[i]) return true;
        if (x.b[i] > y.b[i]) return false;
    }
    return false;
}

bool check(node x, node y) {
    if (x.len != y.len) return false;
    for (int i = 0; i < x.len-1; ++i) {
        if (x.b[i] != y.b[i]) return false;
    }
    return true;
}

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a[i].len = s.size();
        for (int j = 1; j < a[i].len; ++j) {
            int diff = (s[j] - s[j-1] + 26) % 26;
            a[i].b.push_back(diff);
        }
        a[i].s = s;
    }
    sort(a, a + n, cmp);
    // printf("\n");
    // for (int i = 0; i < n; ++i) {
    //     // printf("len=%d\n", a[i].len);
    //     // for (int j = 0; j < a[i].len-1; ++j) {
    //     //     printf("%d ", a[i].b[j]);
    //     // }
    //     // printf("\n");
    //     printf("%s\n", a[i].s.c_str());
    // }
    for (int i = 0; i < n; ++i) {
        int j;
        for (j = i; j < n && check(a[i], a[j]); ++j);
        // printf("i=%d j=%d\n", i, j);
        i = j - 1;
        ans++;
    }
    printf("%d\n", ans);

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}

/*
1 2 3 5 7 9 
  1 1 2 2 2
    0 1 0 0

10 9 8 7 6 3 5 7 9 11
  -1-1-1-1-3 2 2 2 2
     0 0 0-2 5 0 0 0
*/