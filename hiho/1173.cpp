#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;


bool v[20111];
int n, f[20111], ans, mn, nxt[20111], prv[20111];

void work() {

    memset(v, 0, sizeof(v));
    mn = 1;
    for (int i = 0; i <= 20000; ++i) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    for (int i = 1; i <= 20000; ++i) {
        memset(v, 0, sizeof(v));
        for (int j = 0; j < i; ++j) {
            v[f[j]] = 1;
        }
        for (int j = i>>1; j < i; ++j) {
            v[f[j]^f[i-j]] = 1;
        }
        for (int j = nxt[0]; j <= 20000; j = nxt[j]) {
            if (!v[j]) {
                f[i] = j;
                break;
            }
        }
        prv[nxt[f[i]]] = prv[f[i]];
        nxt[prv[f[i]]] = nxt[f[i]];
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ans ^= f[x];
    }
    if (ans) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }


}

int main() {

    freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
