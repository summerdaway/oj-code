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

char a[] = {2, 2, 2, 3, 3, 3, 4, 4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
map<long long, int> f;
int n, m;
char ch[20];

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        long long x = 0;
        int len = strlen(ch);
        for (int j = 0; j < len; ++j) {
            x = x * 10 + a[ch[j]-'A'];
        }
        f[x] += 1;
    }
    for (int i = 0; i < m; ++i) {
        long long x;
        scanf("%lld", &x);
        printf("%d\n", f[x]);
    }

}

int main() {

    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}