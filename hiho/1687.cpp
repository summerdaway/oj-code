#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n, x, y;
long long X, Y;

struct node
{
    long long x, y;
    int l;
};
node a[101111];

long long cross(long long X1, long long Y1, long long X2, long long Y2) {
    return X1*Y2-X2*Y1;
}

void work() {
    scanf("%d", &n);
    x = -1;
    Y = 100000000;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        if (a[i].y < Y || (a[i].y == Y && a[i].x < X)) {
            Y = a[i].y;
            X = a[i].x;
            x = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != x) {
            y = i;
            for (; i < n; ++i) {
                if (i != x && cross(a[i].x - X, a[i].y - Y, a[y].x - X, a[y].y - Y) < 0) {
                    y = i;
                }
            }
        }
    }
    printf("%d %d\n", x + 1, y + 1);

}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}