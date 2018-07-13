#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m;
long long ans, g[2], a[200100], L, R;
map<long long, int> f;

void add(long long x) {
    if (f[x] == 0) {
        f[x] = ++m;
        a[m-1] = x;
    }
}

void case1(long long x) {
    long long t = 0;
    long long xx = x;
    long long p = 1;
    while (xx) {
        t = t * 10;
        t += xx % 10;
        xx /= 10;
        p *= 10;
    }
    long long t1 = x*p + t;
    long long t2 = x/10 * p + t;
    //printf("%lld\n", x);
    //printf("%lld %lld\n", t1, t2);
    add(t1);
    add(t2);
}

long long get_ct(long long x) {
    return x*(x+1)/2;
}

void calc(int st) {
    ans = get_ct(a[st] - L);
    g[0] = a[st] - L + 1;
    for (int i = st; i < m; ++i) {
        if (a[i] > R) {
            break;
        }
        int x = (i - st) & 1;
        x ^= 1;
        ans += g[x] * (min(a[i+1], R+1) - a[i]) + get_ct(min(R+1, a[i+1]) - a[i]-1);
        g[x] += a[i+1] - a[i];
    }   
    printf("%lld\n", ans);
}

void work() {
    scanf("%lld%lld", &L, &R);
    for (int i = 0; i < m; ++i) {
        if (a[i] >= L) {
            if (a[i] > R) {
                printf("%lld\n", get_ct(R - L + 1));
                return;
            }
            calc(i);
            break;
        }
    }
}

int main() {

    for (int i = 1; i < 100000; ++i) {
        case1(i);
    }
    sort(a, a + m);

    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}