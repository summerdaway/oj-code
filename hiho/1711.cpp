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

int fa[101111], b[1001111];
struct node {
    int x, h, toth, shift, diff;
} a[101111];
int n;
set<int> f;
char ch[10];


int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    int y = find(fa[x]);
    a[x].diff += a[fa[x]].diff;
    return fa[x] = y;
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
    if (a[x].diff != 0) {
        printf("x:%d diff:%d\n", x, a[x].diff);
    }
    a[x].diff = a[y].toth;
    a[y].toth += a[x].toth;
}

void work() {
    //freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    int i = 0;
    while (n--) {
        scanf("%s", ch);
        if (ch[0] == 'I') {
            ++i;
            int x, h;
            scanf("%d%d", &x, &h);
            a[i].x = x, a[i].h = a[i].toth = h;
            a[i].diff = 0;
            if (f.size() == 0) {
                f.insert(x);
                b[x] = i;
            } else {
                set<int>::iterator iter = f.upper_bound(x);
                set<int>::iterator iter1 = iter;
                if (iter != f.begin()) {
                    iter--;
                    int idx = b[*iter], idxy = (*iter) + a[idx].toth;
                    // printf("idx=%d idxy=%d\n", idx, idxy);
                    if (idxy >= x) {
                        Union(i, idx);
                    } else {
                        f.insert(a[i].x + a[i].shift);
                        b[a[i].x+a[i].shift] = i;
                        iter = f.find(a[i].x + a[i].shift);
                    }
                } else {
                    f.insert(a[i].x + a[i].shift);
                    b[a[i].x+a[i].shift] = i;
                    iter = f.find(a[i].x + a[i].shift);
                }
                iter++;
                iter1 = iter;
                int prevY = a[find(i)].x + a[find(i)].shift + a[find(i)].toth;
                // printf("prevY=%d %d\n", prevY, iter == f.end());
                for (;iter != f.end(); ++iter) {
                    if (prevY < *iter) break;
                    // printf("union %d %d\n", b[*iter], i);
                    Union(b[*iter], i);
                    // a[find(b[*iter])].shift += prevY - (*iter);
                    prevY = a[find(b[*iter])].x + a[find(b[*iter])].shift + a[find(b[*iter])].toth;
                }
                for (;iter1 != iter;) {
                    // printf("erase:%d\n", *iter1);
                    // printf("%d %d\n", *iter, *iter1);
                    set<int>::iterator iter2 = iter1;
                    iter2++;
                    f.erase(iter1);
                    iter1 = iter2;
                    // printf("here\n");
                }
                // printf("aa\n");
            }
            // for (int j = 1; j <= i; ++j) {
            //     find(j);
            // }
            // printf("m=%d\n", i);
            // for (int j = 1; j <= i; ++j) {
            //     x = j;
            //     int y = find(x);
            //     printf("aa %d %d\n", a[y].x + a[y].shift + a[x].diff, a[y].x + a[y].shift + a[x].diff + a[x].h);
            // }
        } else {
            int x;
            scanf("%d", &x);
            int y = find(x);
            // printf("y=%d a[y].x=%d shift=%d diff=%d\n", y, a[y].x, a[y].shift, a[x].diff);
            printf("%d %d\n", a[y].x + a[y].shift + a[x].diff, a[y].x + a[y].shift + a[x].diff + a[x].h - 1);
        }
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

/*
Problem >_{
    n个操作，(I x y) 表示在高度 x 插入一段高为 h 的区间，插入规则为：
    1. 如果高度 x 有其他区间，那么把 x 移到后面第一个没有被区间覆盖的位置
    2. 在可以插入的位置上，如果 (x, x + h - 1) 会覆盖现有区间，那么现有区间往后平移到 (x + h) 开始，对后面的区间依次这样做，直到不会覆盖下一个区间
    (Q x) 查询第 x 个插入的区间现在在什么位置
    $n\le 100000$
}_<

Solution >_{
    可以看到区间依次后移的时候，它们从此一定是一起移动的，所以可以合并成一个大区间，用并查集合并，对每个区间记录它属于哪个大区间，它相对于大区间的差是多少，大区间就是并查集的根，要记录它相对最开始位置的位移是多少

    对于每个插入 (x, h)，需要快速地查询 x 是否在某个区间里，以及比 x 大的第一个区间是什么，可以用 set 记录所有区间起点，并记录这个起点对应的区间是第几个插入的
    1. 如果set为空，直接插入，b[x] = m
    2. 否则找第一个比 x 大的区间 iter
        1. 如果iter不是最小的区间，那么判断一下前一个区间是否包含 x，如果包含，把 x 调整到这个区间的结尾，并且合并前一个区间和当前区间
        2. 如果不满足1，那么 x 不需要更改，把 x 插入 set，b[x] = m
    3. 从 x 的下一个区间开始，如果下一个区间的开头在当前区间内部或相等，就将下一个区间的开头往后推到当前区间结尾，合并两个区间

    注意
    1. 清楚是否应该插入 x，以及b[x] = m的位置不能早于调整x，否则会覆盖掉之前x相同的区间
    2. 两个相邻的区间，前一个的结尾等于后一个的开头，意味着两个区间之间不能插入任何东西，即使后一个区间的开头不需要变化，也要合并两个区间
    3. 算diff的时候，要在递归完成以后，再用fa的diff更新当前的diff

}_<
*/