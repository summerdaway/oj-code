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

int a[101111], v[101111];

void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    int j = 1;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
        v[a[i]] = true;
    }
    for (int i = 0; i < m; ++i) {
        while (j <= a[i]) {
            if (!v[j]) printf("%d\n", j);
            ++j;
        }
        printf("%d\n", a[i]);
    }
    while (j <= n) {
        if (!v[j]) {
            printf("%d\n", j);
        }
        ++j;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1, Case = 0;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        Case ++;
        //printf("Case #%d: ", Case);
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
