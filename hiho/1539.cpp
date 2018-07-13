#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

char ch[10];
int n, st, ed, dist[20000000];
queue<int> q;

void print(int x) {
    while (x) {
        printf("%d ", x & 7);
        x >>= 3;
    }
    printf("\n");
}

void work() {
    scanf("%s", ch);
    n = strlen(ch);
    st = 0;
    for (int i = 0; i < n; ++i) {
        int x = ch[i] - '1';
        st <<= 3;
        st |= x;
    }
    ed = 0;
    for (int i = 0; i < n; ++i) {
        ed <<= 3;
        ed |= i;
    }
    while (!q.empty()) q.pop();
    q.push(st);
    memset(dist, -1, sizeof(dist));
    dist[st] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == ed) break;
        for (int i = 1; i < n; ++i) {
            int t1 = (i-1) * 3, t2 = (i+1) * 3;
            int x = (now >> t1) & 63, y = (now >> t2 << t1) | (now & ((1 << t1) - 1));
            //printf("x=");
            //print(x);
            //printf("y=");
            //print(y);
            for (int j = 0; j <= n - 2; ++j) {
                int t3 = j*3;
                int z = (y & ((1<<t3)-1)) | (x << t3) | (y >> t3 << (t3 + 6));
                //printf("z=");
                //print(z);
                if (dist[z] == -1) {
                    q.push(z);
                    dist[z] = dist[now] + 1;
                }
            }
        }
    }
    printf("%d\n", dist[ed]);


}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        work();
    }
}