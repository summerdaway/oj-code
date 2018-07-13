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

int n;
long long b[1000111], MOD = 1000000007;


void work() {
    scanf("%d", &n);
    b[1] = 1;
    b[2] = 3;
    for (int i = 3; i <= n; ++i) {
        b[i] = b[i-1]*(i*2-1)%MOD - b[i-2]*(i-1)%MOD*(i-1)%MOD;
        b[i] = (b[i]%MOD+MOD)%MOD;
    }
    printf("%lld\n", b[n]);
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
