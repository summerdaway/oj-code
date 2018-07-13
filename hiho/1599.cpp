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

/*
50 2
50 52
50 102
152 102
152 254
102 52
102 18
84 18
66 18
48 18
30 18
12 18
12 6
6 6
6 0

*/

bool gcd(int a, int b, int x, int y) {
    if (a < b) {
        swap(a, b);
        swap(x, y);
    }
    if (a < x || b < y) {
        return false;
    }
    if (b == y) {
        return (a-x)%b == 0;
    }
    if ((a-x) % b == 0) {
        return gcd(x, b, x, y);
    }
    return gcd(a%b, b, x, y);
}

void work() {
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    if (gcd(a, b, x, y)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}




/*
Problem >_{
    二维格子，你在位置(x, y)，出口在(a, b)，每次只能走到(x+y, y)或(x, y+x)，问能不能走出去，范围10^9
}_<

Solution >_{
    对(a, b)求gcd，求的过程，(a, b, x, y)，如果a减去若干个b可以得到x，那么继续算(x, b)，否则算(a%b, b)，注意交换a和b时同时交换x和y
}_<