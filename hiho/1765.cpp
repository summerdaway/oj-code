
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

int n, a[20], b[20], N;
long long f[20][5000];

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    N = 1 << n;
    f[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < n; ++k) {
                if (!((j>>k)&1) && b[k] >= a[i]) {
                    f[i+1][j^(1<<k)] += f[i][j];
                }
            }
        }
    }
    printf("%lld\n", f[n][N-1]);
}

int main() {

    // freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}



/*
Problem >_{
    给n个男生和n个女生，能力值分别为$a_i$和$b_i$，男生女生能配对要满足$a_i <= b_j$，求配对成n对的方案数。$n<=12$
}_<

Solution >_{
    f(s, i)表示女生选择的状态为s时，前i个男生可以与她们配对的方案数
    f(s, i) = f(t, i-1) (j没在t中选过，t^(1<<j)=s, $a_i\le b_j$)
}_<
*/


