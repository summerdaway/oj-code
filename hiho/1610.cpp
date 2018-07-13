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

int n;

void output(int x) {
    printf("%d", x + 1);
    int t = 1;
    for (int i = 1; i <= n/2; ++i) {
        printf(" %d", (x + i + n) % n + 1);
        if (i < (n+1)/2 || (i == n/2 && (n&1))) printf(" %d", (x - i + n) % n + 1);
        t = -t;
    }
    printf("\n");


}
void work() {
    scanf("%d", &n);
    printf("%d\n", (n+1)/2);
    for (int i = 0; i < (n+1)/2; ++i) {
        output(i);
    }

}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    for (int i = 1; i <= TC; ++i) {
        work();
    }
    return 0;
}