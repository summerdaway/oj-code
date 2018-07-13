#include <map>
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
#include <set>
using namespace std;

int n;
long long c, a[55], ans;

int main() {
	scanf("%d%lld", &n, &c);
	for (int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	int l = 0;
	bool flag = true;
	for (int i = 62; i >= 0; --i) {
		if (c >> i & 1) {
			int ct = 0;
			while (l < n && a[l] >= (1LL<<i)) {
				if (a[l] == (1LL<<i)) ct++;
				++l;
			}
			ans += 1LL << (n-l);
			if (!ct) {
				break;
			}
			if (i == 0) ans++;
		}
	}
	printf("%lld\n", ans - 1);
}