#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
using LL = int64_t;
using LD = long double;
const LL INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n, c;
    cin >> n >> c;
    vector<LL> a(n);
    for (auto& i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    LL ans = 0;
    int k = 0;
    while (k < n) {
        while (k < n && a[k] > c) k++;
        if (n == k) break;
        ans += 1LL << (n - k - 1);
        c -= a[k];
        k++;
    }
    cout << ans << '\n';
}
