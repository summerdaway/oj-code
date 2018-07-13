#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

char s[101111];
int a[30], ans[101111], n;

void work() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        a[s[i]-'a']++;
    }
    for (int i = 0; i < n; ++i) {
        int x = 0, k = -1;
        for (int j = 0; j < 26; ++j) {
            if (a[j] > x) {
                x = a[j];
                k = j;
            }
        }
        if (x > (n-i+1)/2) {
            printf("INVALID\n");
            return;
        } else if (x*2 == (n-i+1)) {
            ans[i] = k;
            a[k]--;
        } else {
            for (int j = 0; j < 26; ++j) {
                if (a[j] && (i == 0 || j != ans[i-1])) {
                    ans[i] = j;
                    a[j]--;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%c", 'a' + ans[i]);
    }
    printf("\n");
}

int main() {
    int TC = 1;
    while (TC--) {
        work();
    }
}


/*
Problem >_{
    给一个只包含小写字母的字符串S($|S|\le 100000$)，重新调整字母位置使得相邻两个字母不相同，求字典序最小的方案。如果没有可行解输出INVALID。
}_<

Solution >_{
    依次枚举位置$i$，每次找是否有字母的个数大于$\lfloor \frac{n-i+1}{2}\rfloor$，如果有，那么无解。否则如果当前剩余字符串长度为奇数，且有字母个数等于长度一半，那么这个字母必须放在开头。否则就找最小的字母放进去。
}_<
*/