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

char s[101111];
struct node {
    int a[600], next, prev, n, mark;
} a[1000];
int n, m, p, q;
set<int> S;


void print() {
    for (int i = a[0].next; i != 0; i = a[i].next) {
        if (a[i].mark) {
            for (int j = a[i].n-1; j >= 0; --j) {
                printf("%c", s[a[i].a[j]]);
            }
        } else {
            for (int j = 0; j < a[i].n; ++j) {
                printf("%c", s[a[i].a[j]]);
            }
        }
    }
    printf("\n");
}

void remove_mark(int st) {
    if (a[st].mark) {
        reverse(a[st].a, a[st].a + a[st].n);
        a[st].mark = 0;
    }
}

void work() {
    scanf("%s", s);
    n = strlen(s);
    m = max((int) sqrt(n), 580);
    a[0].next = 1;
    a[1].prev = 0;
    p = a[0].next;
    for (int i = 0; i < n; ++i) {
        a[p].a[a[p].n++] = i;
        if (a[p].n == m) {
            a[p].next = p+1;
            a[p+1].prev = p;
            p++;
        }
    }
    if (a[p].n > 0) p++;
    else a[a[p].prev].next = 0;
    for (int i = p + 10; i < 2000; ++i) {
        S.insert(i);
    }
    scanf("%d", &q);
    while (q--) {
        // printf("\n");
        // for (int i = a[0].next; i != 0; i = a[i].next) {
        //     printf("aa%d %d\n", i, a[i].n);
        // }
        int l, r;
        scanf("%d%d", &l, &r);
        l++, r++;
        int ll = l, rr = r;
        int st = a[0].next;
        for (;st != 0; st = a[st].next) {
            if (l <= a[st].n) break;
            l -= a[st].n;
        }
        int ed = a[0].next;
        for (;ed != 0; ed = a[ed].next) {
            if (r <= a[ed].n) break;
            r -= a[ed].n;
        }
        // printf("st=%d ed=%d\n", st, ed);
        if (st == ed) {
            l--, r--;
            remove_mark(st);
            // printf("l=%d r=%d\n", l, r);
            for (int i = l; i <= r; ++i) {
                if (i < (r-(i-l))) {
                    // printf("i=%d %d\n", i, r-(i-l));
                    swap(a[st].a[i], a[st].a[r-(i-l)]);
                }
            }
            // print();
            continue;
        }
        remove_mark(st);
        remove_mark(ed);
        set<int>::iterator iter = S.begin();
        p = *iter;
        S.erase(iter);
        for (int i = l-1; i < a[st].n; ++i) {
            a[p].a[a[p].n++] = a[st].a[i];
        }
        a[p].prev = st;
        a[p].next = a[st].next;
        a[st].next = p;
        a[a[p].next].prev = p;
        a[st].n = l - 1;

        iter = S.begin();
        p = *iter;
        S.erase(iter);
        for (int i = 0; i < r; ++i) {
            a[p].a[a[p].n++] = a[ed].a[i];
        }
        for (int i = r; i < a[ed].n; ++i) {
            a[ed].a[i-r] = a[ed].a[i];
        }
        a[ed].n -= r;
        a[p].prev = a[ed].prev;
        a[p].next = ed;
        a[ed].prev = p;
        a[a[p].prev].next = p;
        for (int i = a[st].next; i != ed; i = a[i].next) {
            a[i].prev = a[i].next;
            a[i].mark = 1 - a[i].mark;
            // printf("i=%d\n", i);
        }
        int nxt = ed;
        for (int i = a[st].next; i != ed; i = a[i].prev) {
            a[i].next = nxt;
            nxt = i;
        }
        a[ed].prev = a[st].next;
        a[st].next = p;
        a[p].prev = st;
        p++;
        // for (int i = a[0].next; i != 0; i = a[i].next) {
        //     printf("i=%d prev=%d next=%d ct=%d\n", i, a[i].prev, a[i].next, a[i].n);
        // }
        // printf("here\n");
        for (int i = a[0].next; i != 0; i = a[i].next) {
            while (i != 0 && a[i].next && a[i].n + a[a[i].next].n <= m) {
                // printf("i=%d %d\n", i, a[0].next);
                int t = a[i].next;
                remove_mark(i);
                remove_mark(t);
                for (int j = 0; j < a[t].n; ++j) {
                    a[i].a[j+a[i].n] = a[t].a[j];
                }
                a[i].n += a[t].n;
                a[i].next = a[t].next;
                a[a[t].next].prev = i;
                i = a[i].next;
                S.insert(t);
                memset(a[t].a, 0, sizeof(a[t].a));
                a[t].n = a[t].mark = a[t].next = a[t].prev = 0;
            }
        }

        // for (int i = a[0].next; i != 0; i = a[i].next) {
        //     printf("i=%d prev=%d next=%d ct=%d\n", i, a[i].prev, a[i].next, a[i].n);
        // }
        // print();


        // break;
        // printf("q=%d\n", q);
    }
    // return;
    print();

}

int main() {

    freopen("input.txt", "r", stdin);
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}
