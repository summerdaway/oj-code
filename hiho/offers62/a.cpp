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

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	int z = 1;
	if (x > y) {
		swap(x, y);
		z = -1;
	}
	if (y - x < (x + 360 - y)) {
		printf("%d\n", z*(y-x));
	} else {
		printf("%d\n", -z*(x+360-y));
	}
}