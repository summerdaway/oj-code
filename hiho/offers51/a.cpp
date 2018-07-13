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

int n, m, x, y, a, b, c, d, g1, g2, aa, cc, bb, dd, ans, ag, bg;

int gcd(int qa , int qb) {
   if(qb==0) return qa;
   qa%=qb;
   return gcd(qb,qa);
}

int calc(int xt, int yt) {
    int ct1 = 0, ct2 = 0;
    // printf("xt=%d yt=%d\n", xt, yt);
    if (xt > 0) {
        ct1 = (n-x)/xt + 1;
        // if ((n-x)%xt == 0) {
        //     ct1++;
        // }
    } else if (xt < 0) {
        ct1 = (x-1)/-xt + 1;
    }
    if (yt > 0) {
        ct2 = (m-y)/yt + 1;
        // if ((m-y)%yt == 0) {
        //     ct2++;
        // }
    } else if (yt < 0) {
        ct2 = (y-1)/-yt + 1;
    }
    printf("ct1=%d ct2=%d\n", ct1, ct2);

    if (xt == 0 && yt == 0) {
        return 1;
    }
    if (xt == 0) {
        return ct2;
    }
    if (yt == 0) {
        return ct1;
    }
    return min(ct1, ct2);
}

void work() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a == 0 && b == 0) {
        printf("%d\n", calc(c, d));
        return;
    }
    if (c == 0 && d == 0) {
        printf("%d\n", calc(a, b));
        return;
    }
    g1 = gcd(a, b);
    g2 = gcd(c, d);
    aa = a/g1, bb = b/g1;
    cc = c/g2, dd = d/g2;
    // printf("g1=%d g2=%d aa=%d\n", g1, g2, aa);
    if (!(aa==cc && bb==dd)) {
        // printf("l1=%d l2=%d\n", calc(a,b), calc(c,d));
        ans = calc(a, b) + calc(c, d) - 1;
        // printf("here\n");
    } else {
        int g = gcd(g1, g2);
        int k = g2/g;
        ag = a*k, bg = b*k;
        // printf("ag=%d bg=%d %d\n", ag, bg, calc(ag, bg));
        ans = calc(a, b) + calc(c, d) - calc(ag, bg);
    }
    printf("%d\n", ans);

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}

/*
1 2 3 5 7 9 
  1 1 2 2 2
    0 1 0 0

10 9 8 7 6 3 5 7 9 11
  -1-1-1-1-3 2 2 2 2
     0 0 0-2 5 0 0 0
*/