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
    int st = 7;
    for (int s = 0; s < 256; s ++) {
        int now = st;
        for (int i = 0; i < 8; i ++) {
            if ((s >> i) & 1) {
                for (int j = -1; j <= 1; j ++) {
                    int k = (i + j + 8) % 8;
                    now ^= 1 << k;
                }
            }
        }
        if (now == 255) {
            for (int i = 0; i < 8; i ++)
                printf("%d", (s >> i) & 1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    int t = clock();
#endif
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
