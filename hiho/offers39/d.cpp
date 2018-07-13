#prag\
ma GCC optimize ("O4") 
#include <map>
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


void add(int idx) {
    int now = 0;
    int len = strlen(ch);
    for (int i = 0; i < len; ++i) {
        int x = ch[i] - 'a';
        if (!T[now].next[x]) {
            T[now].
        }
    }
}

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", ch, &v[i]);
        add(i);
        add1(i);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = clock();
#endif
    int TestCase = 1;
    //scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
#ifndef ONLINE_JUDGE
    cerr << "time = " <<  clock() - t << " ms" << endl;
#endif
    return 0;
}

