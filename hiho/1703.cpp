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

int n, a[50];
long long K, f[50];

void calc(int l, int r, long long k) {
    if (l == r) return;
    vector<pair<int, pair<long long, long long> > > b;
    for (int i = l; i < r; ++i) {
        b.push_back(make_pair(a[i], make_pair(f[i-l], f[r-i-1])));
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < r - l; ++i) {
        long long nl = b[i].second.first, nr = b[i].second.second;
        // printf("l=%d r=%d nl=%lld nr=%lld x=%d k=%lld\n", l, r, nl, nr, b[i].first, k);
        if (nl*nr >= k) {
            printf("%d\n", b[i].first);
            for (int j = l; j < r; ++j) {
                if (a[j] == b[i].first) {
                    calc(l, j, (k-1)/nr + 1);
                    calc(j + 1, r, (k-1)%nr + 1);
                }
            }
            break;
        } else {
            k -= nl*nr;
        }
    }
}

void work() {
    scanf("%d%lld", &n, &K);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = 0;
        for (int j = 0; j < i; ++j) {
            f[i] += f[j] * f[i-1-j];
        }
    }
    calc(0, n, K);

}

int main() {
    //  freopen("input.txt", "r", stdin);
    int TestCase = 1;
    // scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
