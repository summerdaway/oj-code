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
set<int> x, y;

void work() {
    x.insert(1);
    y = x;
    x.insert(2);
    printf("%d %d\n", x.size(), y.size());
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = clock();
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
