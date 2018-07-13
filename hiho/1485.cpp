#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

char ch[101111];
int a[500], n, st, ans;

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    ans = n + 1;
    st = 0;
    for (int i = 0; i < n; ++i) {
        a[ch[i]]++;
        if (ch[i] == 'h' && a[ch[i]] > 2) {
            while (st < i && ch[st] != 'h') {
                a[ch[st]]--;
                st++;
            }
            a['h']--;
            st++;
        }
        if (ch[i] == 'o' && a['o'] > 1) {
            while (st < i && ch[st] != 'o') {
                a[ch[st]]--;
                st++;
            }
            a['o']--;
            st++;
        }
        if (ch[i] == 'i' && a['i'] > 1) {
            while (st < i && ch[st] != 'i') {
                a[ch[st]]--;
                st++;
            }
            a['i']--;
            st++;
        }
        while (st < i && ch[st] != 'h' && ch[st] != 'o' && ch[st] != 'i') {
            a[ch[st]]--;
            st++;
        }
        if (a['h'] == 2 && a['i'] == 1 && a['o'] == 1) {
            ans = min(ans, i - st + 1);
        }
    }
    printf("%d\n", ans > n ? -1 : ans);

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}