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

int a[111], n, m;

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for (int j = m; j; --j) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] == i && i + j <= n && a[i] < a[i+j]) {
                swap(a[i], a[i+j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d", a[i]);
        printf(i == n ? "\n" : " ");
    }

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
