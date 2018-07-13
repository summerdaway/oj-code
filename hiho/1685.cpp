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

int n, m, K, a[311][311], ct, T[101111], ans;
long long s[311];
pair<long long, int> b[311];

int query(int x) {
    int ret = x;
    for (int i = x; i; i -= i&-i) {
        ret = min(ret, T[i]);
    }
    return ret;
}

void insert(int x) {
    for (int i = x; i <= m + 1; i += i&-i) {
        T[i] = min(T[i], x);
    }
}


int calc(int nl) {
    int ret = 0;
    for (int i = 0; i <= m; ++i) {
        b[i].first = s[i];
        b[i].second = i + 1;
    }
    sort(b, b + m + 1);
    for (int i = 1; i <= m + 1; ++i) {
        T[i] = m + 10;
    }
    int j = m;
    for (int i = m; i >= 0; --i) {
        while (j >= 0 && b[i].first - b[j].first <= K) {
            insert(b[j].second);
            j--;
        }
        ret = max(ret, nl*(b[i].second - query(b[i].second)));
    }
    return ret;
}

void work() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        memset(s, 0, sizeof(s));
        for (int j = i; j <= n; ++j) {
            long long sum = 0;
            for (int k = 1; k <= m; ++k) {
                sum += a[j][k];
                s[k] += sum;
            }
            ans = max(ans, calc(j-i+1));
        }
    }
    printf("%d\n", ans);
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