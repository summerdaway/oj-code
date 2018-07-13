#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int c[111], s[111];

int count(int x) {
    int ret = 0;
    while (x) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

int calc(int x) {
    int y = 0;
    int x1 = x;
    while (x1) {
        y <<= 1;
        y |= x1 & 1;
        x1 >>= 1;
    }
    return count(x + y);
}


void str2(int x) {
    if (x == 0) return;
    str2(x >> 1);
    printf("%d", x & 1);
}

void work() {
    scanf("%s", a);
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}