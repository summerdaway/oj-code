#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int n;

void print(int x) {
    printf("%02d:%02d\n", x>>6, x&((1<<6)-1));
}

int count(int x) {
    int ret = 0;
    while (x) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

bool check(int x) {
    int h = x >> 6, m = x & ((1<<6)-1);
    return h < 24 && m < 60;
}


void work() {
    scanf("%d", &n);
    for (int i = 0; i < (1<<11); ++i) {
        if (count(i) == n && check(i)) {
            print(i);
        }
    }


}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
