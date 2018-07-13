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

long long ans1, ans2;
int stk[1111], g[1111], p[1111];
int n, ct1, ct2, m;
char ch[1111];
const long long MOD = 1000000007;

void work() {
    scanf("%s", ch);
    n = strlen(ch);

    ct1 = ct2 = 0;
    p[ct1++] = -1;
    for (int i = 0; i < n; ++i) {
        if (ch[i] == '(') {
            stk[ct2++] = i;
        } else if (ch[i] == ')' && ct2) {
            ct2--;
        } else {
            p[ct1++] = i;
        }
    }
    m = ct1;
    for (int i = 0; i < ct2; ++i) {
        p[ct1++] = stk[i];
    }


    p[ct1] = n;
    for (int i = 1; i <= ct1; ++i) {
        int l = p[i-1] + 1, r = p[i];
        //printf("p[i]=%d l=%d r=%d\n", p[i], l, r);
        ct2 = 0;
        for (int j = l; j < r; ++j) {
            if (ch[j] == '(') {
                ct2++;
            } else {
                ct2--;
                if (ct2 == 0) {
                    g[i]++;
                }
            }
        }
    }

    for (int i = 1; i <= ct1; ++i) {
        //printf("%d ", g[i]);
    }

    ans1 = g[1] + 1;
    for (int i = 2; i < m; ++i) {
        //printf("i=%d g=%d\n", i, g[i]);
        ans1 = ans1*(g[i]+2)%MOD;
    }

    ans2 = g[ct1] + 1;
    for (int i = ct1 - 2; i >= m; --i) {
        ans2 = ans2*(g[i+1]+2)%MOD;
    }

    if (m == 1) {
        ans1 = 1;
    }
    if (ct1 == m) {
        ans2 = 1;
    }



    printf("%d %lld\n", ct1 - 1, ans1*ans2% MOD);
}



int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}