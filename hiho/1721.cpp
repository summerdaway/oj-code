
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

char a[501111], b[501111];
int n, m;

bool check(int x) {
    m = 0;
    for (int i = 0; i < n; ++i) {
        if (i != x) {
            b[m++] = a[i];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] != b[m-i-1]) {
            return false;
        }
    }
    return true;
}

void work() {
    scanf("%s", a);
    n = strlen(a);
    int i = 0, j = n - 1;
    while (i < j && a[i] == a[j]) {
        i++, j--;
    }
    if (!check(i)) {
        i = j;
    }
    while (i && a[i] == a[i-1]) {
        i--;
    }
    printf("%d\n", i + 1);
}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
