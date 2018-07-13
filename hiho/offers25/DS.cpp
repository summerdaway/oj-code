#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>

using namespace std;




struct Point {
    int x, y;

    Point(int xx, int yy) {
        x = xx, y = yy;
    }

    Point() {}

    Point operator-(const Point p) {
        return Point(x - p.x, y - p.y);
    }

    bool operator==(const Point p) {
        return x == p.x && y == p.y;
    }

    int len() {
        return x*x + y*y;
    }
};

struct Triangle {
    Point p[3];
    Triangle() {}
};

struct Edge {
    Point x1, x2;

    Edge() {}

    Edge(Point xx1, Point xx2) {
        if (xx1.x < xx2.x) {
            x1 = xx1, x2 = xx2;
        } else {
            x1 = xx2, x2 = xx1;
        }
    }

    int len() {
        Point p = x1 - x2;
        return p.len();
    }
};

Edge Q[100];
Triangle T[10];
bool vt[10], ve[20];
int N, m, A, B, label[20];

bool check(Edge e1, Edge e2) {
    return e1.x2 - e1.x1 == e2.x2 - e2.x1;
}

int get_last(int x, int y) {
    if (x > y) swap(x, y);
    if (x == 0 && y == 1) return 2;
    if (x == 0 && y == 2) return 1;
    return 0;
}

bool work() {

    scanf("%d%d%d", &N, &A, &B);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x, y;
            scanf("%d%d", &x, &y);
            T[i].p[j] = Point(x, y);
        }
    }

    bool flag = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (zhijiao(T[i].p[j], T[i].p[(j+1) % 3], T[i].p[(j-1+3)%3])) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) return false;


    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int tmp1, tmp2;
            tmp1 = tmp2 = -1;
            for (int i1 = 0; i1 < 3; ++i1) {
                for (int j1 = 0; j1 < 3; ++j1) {
                    if (check(Edge(T[i].p[i1], T[i].p[(i1+1) % 3]), Edge([T[j].p[j1], T[j].p[(j1+1)%3]]))) {
                        tmp1 = i1, tmp2 = j1;
                        ve[i*3+i1] = ve[j*3+j1] = true;
                        break;
                    }
                    if (tmp1 != -1) break;
                }
            }
            if (tmp1 == -1) return false;

            int last = get_last(i, j);

        }
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    while (TC--) {
        if (work()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}