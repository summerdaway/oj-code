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


void work() {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= x; ++i) {
        if (x % i == 0)
        for (int j = 1; j <= y; ++j) {
            if (y % j == 0) {
                printf("%d %d\n", i, j);
            }
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
