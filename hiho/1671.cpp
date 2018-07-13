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

char ch[5111111];
int n, st[5111111], s[5111111], m;

void print(int l, int r, int t) {
    // printf("\nl=%d r=%d t=%d\n", l, r, t);
    if (l > r) return;
    if (t == 0) {
        for (int i = l; i <= r; ++i) {
            if (ch[i] == '(') {
                print(i + 1, s[i] - 1, 1);
                i = s[i];
            } else {
                printf("%c", ch[i]);
            }
        }
    } else {
        int prv = l;
        for (int i = r; i >= l; --i) {
            if (ch[i] == ')') {
                print(s[i] + 1, i - 1, 0);
                i = s[i];
            } else {
                printf("%c", ch[i]);
            }
        }
    }
}

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    for (int i = 0; i < n; ++i) {
        if (ch[i] == '(') {
            st[m++] = i;
        } else if (ch[i] == ')') {
            s[st[m-1]] = i;
            s[i] = st[--m];
        }
    }
    print(0, strlen(ch) - 1, 0);
    printf("\n");
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