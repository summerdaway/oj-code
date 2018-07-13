#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
int n;

void work() {
    scanf("%d", &n);
    if (n == 1) {
        printf("1\n");
        return;
    }
        for (int i = 0; 2*i+1 <= n; ++i) {
            printf("%d ", i*2+1);
        }
        for (int i = n/2; i > 1; --i) {
            printf("%d ", i*2);
        }
        printf("2\n");
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    while (TC--) {
        work();
    }
}