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



void work() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("")
    }

}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}


/*
Problem >_{
    给个二叉树，输出垂直遍历
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