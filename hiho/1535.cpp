#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int f[100], a[100], c[100], n, ans;
char ch[100], ch1[100];
bool v[100];


void cover(int x, int y, int d[]) {
    for (int i = 0; i < n; ++i) {
        if (d[i] == x) {
            if (y == 1) {
                d[i] += 26;
            } else {
                for (++i; i < n; ++i) {
                    if (d[i] == x) {
                        d[i] += 26;
                        break;
                    }
                }
            }
            break;
        }
    }
}

int calc() {
    int ret = 0;
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; ++i) {
        f[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            int ct = 1;
            v[i] = true;
            for (int j = f[c[i]]; j != i; j = f[c[j]]) {
                v[j] = true;
                ct++;
            }
            ret += ct - 1;
        }
    }
    return ret;
}

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    ans = 2000000000;

    scanf("%s", ch1);

    for (int i = 0; i < n; ++i) {
        a[i] = ch[i] - 'a';
        c[i] = ch1[i] - 'a';
    }

    cover('m' - 'a', 0, c);
    cover('s' - 'a', 0, c);
    cover('f' - 'a', 0, c);
    cover('t' - 'a', 0, c);

    for (int i1 = 0; i1 < 2; ++i1) {
        for (int i2 = 0; i2 < 2; ++i2) {
            for (int i3 = 0; i3 < 2; ++i3) {
                for (int i4 = 0; i4 < 2; ++i4) {
                    for (int i = 0; i < n; ++i) {
                        a[i] = ch[i] - 'a';
                    }
                    cover('m' - 'a', i1, a);
                    cover('s' - 'a', i2, a);
                    cover('f' - 'a', i3, a);
                    cover('t' - 'a', i4, a);
                    ans = min(ans, calc());
                }
            }
        }

    }
    printf("%d\n", ans);
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}