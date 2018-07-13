
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

int x, y, ct = 10;
bool v[10011101], ans[10];


void work() {
    scanf("%d%d", &x, &y);
    while (1) {
        x *= 10;
        if (v[x]) break;
        v[x] = true;
        if (!ans[x/y]) ct--;
        ans[x/y] = true;
        if (ct == 0) break;
        x %= y;
    }
    for (int i = 0; i < 10; ++i) {
        if (ans[i]) {
            printf("%d", i);
        }
    }
    printf("\n");

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
