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

vector<int> a[5000];
int n;
char ch[101111];
long long ans;

void work() {
    scanf("%s", ch);
    for (int i = 'a'; i <= 'z'; ++i) {
        a[i].push_back(-1);
    }
    n = strlen(ch);
    for (int i = 0; i < n; ++i) {
        a[ch[i]].push_back(i);
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        a[i].push_back(n);
        for (int j = 1; j + 1 < a[i].size(); ++j) {
            long long l = a[i][j] - a[i][j-1], r = a[i][j+1] - a[i][j];
            ans += l * r;
        }
    }
    printf("%lld\n", ans);
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
