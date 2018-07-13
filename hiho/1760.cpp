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

char a[1111], b[1111];
int n1, n2;

void work() {
    scanf("%s%s", a, b);
    n1 = strlen(a);
    n2 = strlen(b);
    int j = 0;
    bool flag = true;
    for (int i = 0; i < n1; i += 2) {
        while (j < n2 && b[j] != a[i]) ++j;
        ++j;
        if (j > n2) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("Yes\n");
        return;
    }
    flag = true;
    j = 0;
    for (int i = 1; i < n1; i += 2) {
        while (j < n2 && b[j] != a[i]) ++j;
        ++j;
        if (j > n2) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
     // freopen("input.txt", "r", stdin);
    int TestCase = 1;
    scanf("%d", &TestCase);
    for (int i = 1; i <= TestCase; ++i) {
        work();
    }
    return 0;
}