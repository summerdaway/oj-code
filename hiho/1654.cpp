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

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int p[20];
queue<int> q;
map<int, int> d, g;
char ch[10];

int get_value(int x, int y, int now) {
    int t = 15 - (x * 4 + y);
    return now/p[t] % 3;
}

pair<int, int> get_pos(int t) {
    t = 15 - t;
    return make_pair(t / 4, t % 4);
}

bool check(int now, int x, int y) {
    int t = get_value(x, y, now);
    if (t == 0) return false;
    bool flag = true;
    for (int i = 0; i < 4; ++i) {
        flag &= get_value(i, y, now) == t;
    }
    if (flag) return true;
    flag = true;
    for (int i = 0; i < 4; ++i) {
        flag &= get_value(x, i, now) == t;
    }
    if (flag) return true;
    if (x == y) {
        flag = true;
        for (int i = 0; i < 4; ++i) {
            flag &= get_value(i, i, now) == t;
        }
        if (flag) return true;
    }
    if (x + y == 3) {
        flag = true;
        for (int i = 0; i < 4; ++i) {
            flag &= get_value(i, 3 - i, now) == t;
        }
        if (flag) return true;
    }
    return false;
}

int set_value(int x, int y, int now, int w) {
    int t = 15 - (x * 4 + y);
    return (now/p[t+1] * 3 + w) * p[t] + now % p[t];
}

int move(int x0, int y0, int x, int y, int now) {
    int ret = set_value(x, y, now, get_value(x0, y0, now));
    return set_value(x0, y0, ret, 0);
}

void print(int x) {
    for (int i = 15; i >= 0; --i) {
        int t = x/p[i]%3;
        if (t== 0) {
            printf("O");
        } else if (t == 1) {
            printf("X");
        } else {
            printf("Y");
        }
        if (i % 4 == 0) {
            printf("\n");
        }
    }
}

void work() {
    g['O'] = 0, g['X'] = 1, g['Y'] = 2;
    p[0] = 1;
    int s = 0;
    for (int i = 1; i <= 16; ++i) {
        p[i] = p[i-1] * 3;
    }
    for (int i = 0; i < 4; ++i) {
        scanf("%s", ch);
        for (int j = 0; j < 4; ++j) {
            s *= 3;
            s += g[ch[j]];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (check(s, i, j)) {
                printf("0\n");
                return;
            }
        }
    }
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 16; ++i) {
            int t = now/p[i] % 3;
            if (t == 0) continue;
            pair<int, int> pos = get_pos(i);
            for (int j = 0; j < 4; ++j) {
                int x = pos.first + dx[j], y = pos.second + dy[j];
                if (x < 0 || y < 0 || x >= 4 || y >= 4 || get_value(x, y, now) != 0) continue;
                int nw = move(pos.first, pos.second, x, y, now);
                if (d.find(nw) == d.end()) {
                    d[nw] = d[now] + 1;
                    if (check(nw, x, y)) {
                        printf("%d\n", d[nw]);
                        print(nw);
                        return;
                    }
                    q.push(nw);
                }
            }
        }
    }
    printf("-1\n");
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