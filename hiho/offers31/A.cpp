#include <map>
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

long long ans;
int n, a[101111], head, tail;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    head = 0, tail = 0;
    for (int i = 0; i < n; ++i) {
        while (head < n && (a[head]-8)*8 < a[i]) head++;
        if (a[i] < 88888) {
            while (tail < n && a[tail] <= 8*a[i] + 8 && a[tail] <= 88888) tail++;
        } else {
            while (tail < n && a[tail] <= 8*a[i] + 8) tail++;
        }
        //printf("%d %d\n", head, tail);
        ans += tail-head;
    }
    printf("%lld\n", ans-n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
