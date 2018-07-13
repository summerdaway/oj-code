#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <set>

using namespace std;

char ch[1000];
string ans[1000];
int n, m;

void work() {
    gets(ch);
    n = strlen(ch);
    for (int i = 0; i < n; ++i) {
        if (ch[i] == '@') {
            string s = "";
            for (i = i + 1;i < n; ++i) {
                if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z')) {
                    s += ch[i];
                } else {
                    break;
                }
            }
            if (s != "") {
                ans[m++] = s;
            }
            i--;
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%s", ans[i].c_str());
        printf(i == m - 1 ? "\n":" ");
    }

}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}