#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int n, m, dist[1001111], a[10];
map<string, int> f;
queue<string> q;
char ch[10];

void clear() {
    m = 0;
    while (!q.empty()) q.pop();
    memset(dist, -1, sizeof(dist));
    f.clear();
}

void work() {
    clear();
    scanf("%s", ch);
    n = strlen(ch);
    string t = "";
    for (int i = 0; i < n; ++i) {
        t += (i+1) + '0';
        a[i] = i;
    }
    f[t] = ++m;

    string tt = (string) ch;
    if (f[tt] == 0) {
        f[tt] = ++m;
    }

    q.push(tt);
    dist[f[tt]] = 0;

    while (!q.empty()) {
        string s = q.front();
        int ii = f[s];

        if (ii == 1) break;

        q.pop();
        for (int i = 1; i < n; ++i) {
            string s1 = s.substr(0, i - 1), s2 = s.substr(i - 1, 2), s3 = s.substr(i + 1, n);

            int len = s1.size();
            for (int j = 0; j < s1.size(); ++j) {
                string tmp1 = s1.substr(0, j), tmp2 = s1.substr(j, len);
                string tmp = tmp1 + s2 + tmp2 + s3;
                if (f[tmp] == 0) {
                    f[tmp] = ++m;
                }
                int idx = f[tmp];
                if (dist[idx] == -1) {
                    dist[idx] = dist[ii] + 1;
                    q.push(tmp);
                }
            }

            string tmp1 = "", tmp2 = s3;
            len = s3.size();
            for (int j = 1; j <= len; ++j) {
                tmp1 += tmp2[0];
                tmp2 = tmp2.substr(1, len);
                //string tmp1 = s3.substr(0, j), tmp2 = s3.substr(j, s3.size());
                string tmp = s1 + tmp1 + s2 + tmp2;
                if (f[tmp] == 0) {
                    f[tmp] = ++m;
                }
                int idx = f[tmp];
                if (dist[idx] == -1) {
                    dist[idx] = dist[ii] + 1;
                    q.push(tmp);
                }
            }
        }
    }
    printf("%d\n", dist[1]);


}


int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }

}