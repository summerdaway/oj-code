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

long long y, ansx, ans;
int a[20], n;
char ch[20];

void print(long long x, int y) {
    if (y == 0) {
        return;
    }
    print(x/10, y-1);
    printf("%d", x%10);
}

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    y = 0;
    long long P = 1;
    for (int i = 0; i < n; ++i) {
        y += P*(ch[n-i-1]-'0');
        P *= 10;
    }
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }
    do {
        long long x = 0;
        for (int i = 0; i < n; ++i) {
            x *= 10;
            x += a[i];
        }
        long long d = min(abs(x - y), P - abs(x-y));
        if (d > ans) {
            ans = d;
            ansx = x;
        } else if (d == ans) {
            ansx = min(ansx, x);
        }
    } while (next_permutation(a, a + 10));
    print(ansx, n);
    printf("\n");
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}