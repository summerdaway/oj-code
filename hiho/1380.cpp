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

int n, N, M, f[5000000], ans[5000000], g[20000], p[30], ct[5000000];
bool v[5000000];
char ch[20000];



void print(int x) {
    for (int i = n - 1; i >= 0; --i) {
        printf("%d", x/p[i]%3);
    }
    printf("\n");
}

void work() {
    p[0] = 1;
    for (int i = 1; i <= 15; ++i) {
        p[i] = p[i-1]*3;
    }
    scanf("%d", &n);
    scanf("%s", ch);
    M = 1 << n;
    for (int i = 0; i < M; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum *= 3;
            sum += i>>j&1;
        }
        g[i] = sum;
        if (ch[i] == '1') {
            f[sum] = 2;
        } else {
            f[sum] = 1;
        }
        ans[sum] = n;
    }
    N = p[n];
    for (int i = 0; i < N; ++i) {
        ct[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i/p[j] % 3 != 2) {
                ct[i] += 1;
            }
        }
    }
    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < n; ++k) {
            if (j/p[k] % 3 != 2) {
                int x = j/p[k+1] * p[k+1] + j%p[k];
                f[x+2*p[k]] |= f[x] | f[x+1*p[k]];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        ans[i] = n;
    }

    for (int i = N - 1; i >= 0; --i) {
        if (f[i] != 3) {
            ans[i] = min(ans[i], ct[i]);
            // printf("ct=%d ", ans[i]);
            // print(i);
        }
        for (int j = 0; j < n; ++j) {
            if (i/p[j] % 3 == 2) {
                int x = i/p[j+1]*p[j+1] + i%p[j];
                // printf("ans[i]=%d\n", ans[i]);
                // print(x+p[j]);
                // print(x);
                ans[x+p[j]] = min(ans[x+p[j]], ans[i]);
                ans[x] = min(ans[x], ans[i]);
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        printf("%d", ans[g[i]]);
        printf(i == M - 1 ? "\n" : " ");
    }




}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}


/*
Problem >_{
    给一个n和$2^n$个数，每个数表示 $f(x), x\in {0, 1}^n$
    定义0-certificate：
    如果f(x) = 0，0-certificate是x的0/1取值的一个子集，只定下这个子集的取值，就可以确定 f 值为0。就是将 x 里某些值固定，其他值随便取，怎么取 f 值都是0
    1-certificate同理
    现在对每个x，求最短的0/1-certificate长度（如果f(x)=0求0-certificate，否则求1-certificate）
}_<

Solution >_{
    先求$f(x)，x\in {0, 1, 2}^n$，$x_i=2$表示这一位随便取，其他两个表示就取那个值。f(x)表示取值为x的情况下，原来给的取值是什么。f(x)=1,2,3表示只会取0、只会取1、0和1都能取到。f(x, i, 0) | f(x, i, 1) -> f(x, i, 2)，就是对x枚举它确定取值的所有位置，将这个位置为0和1的取值转移给随便取的。所以更新的时候，x一定往比它大的更新，所以从0到N枚举就可以。
    然后求g(x), 表示取值为x情况下，最短的certificate是多长。那么如果f(x)不是3，g(x)就等于它确定了取值的那些位的个数。g(x, i, 0) <- g(x), g(x, i, 1) <- g(x)，枚举值为2的那些位置，转移给取0或者取1。从N枚举到0.
}_<