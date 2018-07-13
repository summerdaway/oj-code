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

long long f[111][4];
map<char, int> g;
char a[] = {'h', 'i', 'o'};
string s, s1;
long long n;

void work() {
    scanf("%lld", &n);
    // printf("n=%lld\n", n);
    int m = 100;
    s = "h";
    for (int i = 1; i <= m; ++i) {
        s1 = "";
        for (int j = 0; j < s.size(); ++j) {
            s1 += s[j];
            s1 += a[(g[s[j]]+1) % 3];
        }
        // printf("i=%d %s\n", i, s1.c_str());
        long long tot = 0;
        for (int j = 0; j < s1.size(); ++j) {
            tot += f[m-i+1][g[s1[j]]];
            if (n <= tot) {
                // printf("tot=%lld\n", tot);
                s = s1[j];
                // printf("s1j=%c\n", s1[j]);
                n -= tot - f[m-i+1][g[s1[j]]];
                break;
            }
        }
        // printf("s=%s n=%lld\n", s.c_str(), n);
    }
    printf("%c\n", s[0]);

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = clock();
#endif

    f[1][0] = f[1][1] = f[1][2] = 1;
    for (int i = 2; i <= 100; ++i) {
        f[i][0] = f[i-1][0] + f[i-1][2];
        f[i][1] = f[i-1][0] + f[i-1][1];
        f[i][2] = f[i-1][1] + f[i-1][2];
        for (int j = 0; j < 3; ++j) {
            if (f[i][j] > 1000000000000000) {
                f[i][j] = 1000000000000000;
            }
        }
    }
    g['h'] = 0;
    g['i'] = 1;
    g['o'] = 2;

    int TestCase = 1;
    scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}
