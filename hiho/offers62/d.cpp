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

int n, m, p, tot, k, b[101111], mx, t, q;
char a[101111], ans[101111];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", a);
	sort(a, a + n);
	p = n % m;
	if (p == 0) {
		p = m;
	}
	k = n/m + (n%m != 0);
	t = p;
	tot = p * k;
	int now = 0, round = 0;
	for (int r = 0; r < k; ++r) {
		for (int i = 0; i < p; ++i) {
			b[i] = a[now++] - '0';
		}
		reverse(b, b + p);
		for (int i = 0; i < p; ++i) {
			if (b[i] != b[0]) {
				p = i;
				break;
			}
		}
		ans[q++] = '0' + b[0];
	}
	printf("%s\n", ans);
}