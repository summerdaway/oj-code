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

long long ans;
map<int, int> f;
int n;

void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        ans += f[y-x];
        f[x-y] += 1;
    }
    printf("%lld\n", ans);

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