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

int n, ne, din[101111], dout[101111], m, p;
char ch[20];
string g[101111];
vector<int> a[101111], ve[101111];
map<string, int> f;
char ans[101111];

void dfs(int x) {
    for (int i = 0; i < a[x].size(); ++i) {
        if (!ve[x][i]) {
            ve[x][i] = true;
            ne--;
            dfs(a[x][i]);
        }
    }
    ans[p++] = g[x][g[x].size()-1];
}


void work() {
    scanf("%d", &n);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        scanf("%s", ch);
        if (strlen(ch) == 1) {
            printf("%c", ch[0]);
            flag = true;
            continue;
        }
        string s = (string) ch;
        string s1 = s.substr(0, strlen(ch) - 1);
        string s2 = s.substr(1, strlen(ch));
        if (f[s1] == 0) {
            f[s1] = ++m;
            g[m] = s1;
        }
        if (f[s2] == 0) {
            f[s2] = ++m;
            g[m] = s2;
        }
        int x = f[s1], y = f[s2];
        a[x].push_back(y);
        ve[x].push_back(false);
        din[y]++, dout[x]++;
        ne++;
    }
    if (flag) {
        printf("\n");
        return;
    }


    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum += din[i] - dout[i];
    }
    if (sum != 0) {
        printf("NO\n");
        return;
    }

    int ct = 0;
    for (int i = 1; i <= m; ++i) {
        if (din[i] != dout[i]) ct++;
    }
    if (!(ct == 0 || ct == 2)) {
        printf("NO\n");
        return;
    }

    for (int i = 1; i <= m; ++i) {
        if (dout[i] > din[i]) {
            dfs(i);
            for (int j = g[i].size() - 2; j >= 0; --j) {
                ans[p++] = g[i][j];
            }
            if (ne != 0) {
                printf("NO\n");
                return;
            }
            for (int i = p-1; i >= 0; i--) {
                printf("%c", ans[i]);
            }
            printf("\n");
            return;
        }
    }
    dfs(1);
    if (ne != 0) {
        printf("NO\n");
        return;
    }
    for (int i = g[1].size() - 2; i >= 0; --i) {
        ans[p++] = g[1][i];
    }
    for (int i = p-1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    printf("\n");

}

int main() {

    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}