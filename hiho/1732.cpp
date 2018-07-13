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

void work() {
    int n;
    scanf("%d", &n);
    long long x, y;
    x = 0, y = 1;
    for (int i = 1; i <= n; ++i) {
        long long t = y;
        y = x + y;
        x = t;
    }
    printf("%lld\n", y);

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
