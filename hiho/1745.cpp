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
    long long n, A, B, C;
    scanf("%lld%lld%lld%lld", &n, &A, &B, &C);

    if (B <= C) {
        printf("%lld\n", n*C/A);
    } else {
        long long x = C*n/(A-B+C);
        printf("%lld\n", x + (C*(n-x)-x*(A-B))/A);
    }



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