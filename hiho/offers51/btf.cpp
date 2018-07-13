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

struct node
{
    int x, h;
} a[100], ans[100];
int b[100];
char ch[10];
int p, m, n;

void work() {
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", ch);
        if (ch[0] == 'I') {
            int t, h;
            scanf("%d%d", &t, &h);
            for (int i = 0; i < m; ++i) {
                int j = b[i];
                if (a[j].x <= t && t < a[j].x + a[j].h) {
                    t = a[j].x + a[j].h;
                }
            }
            // printf("t=%d\n", t);
            a[m].x = t, a[m].h = h;
            b[m] = m;
            for (int i = 0; i < m; ++i) {
                int j = b[i];
                if (a[j].x > t) {
                    for (int k = m; k > i; --k) {
                        b[k] = b[k-1];
                    }
                    b[i] = m;
                    for (int k = i + 1; k <= m; ++k) {
                        if (a[b[k]].x < a[b[k-1]].x + a[b[k-1]].h) {
                            a[b[k]].x = a[b[k-1]].x + a[b[k-1]].h;
                        }
                    }
                    break;
                }
            }
            ++m;
            printf("m=%d\n", m);
            for (int i = 0; i < m; ++i) {
                printf("%d %d %d\n", b[i], a[b[i]].x, a[b[i]].x + a[b[i]].h);
            }
        } else {
            int t;
            scanf("%d", &t);
            ans[p++] = a[t-1];
        }
    }

    for (int i = 0; i < p; ++i) {
        cout << ans[i].x << " " << ans[i].x + ans[i].h-1 << "\n";
    }

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}

/*
1 2 3 5 7 9 
  1 1 2 2 2
    0 1 0 0

10 9 8 7 6 3 5 7 9 11
  -1-1-1-1-3 2 2 2 2
     0 0 0-2 5 0 0 0
*/