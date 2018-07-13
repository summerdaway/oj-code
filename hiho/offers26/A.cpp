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

struct Point {
    int x, y;

    Point() {}

    Point(int xx, int yy) {
        x = xx, y = yy;
    }

    Point const operator-(Point that) {
        return Point(x-that.x, y-that.y);
    }
};

int n, u;
Point a[55];

int cross_product(Point p1, Point p2) {
    return p1.x * p2.y - p1.y*p2.x;
}

int area(Point x, Point y, Point z) {
    Point xy = x - y;
    Point zy = z - y;
    return abs(cross_product(xy, zy));
}


Point center(Point x, Point y, Point z) {
    return Point((x.x+y.x+z.x), (x.y+y.y+z.y));
}

double sqr(double x) {
    return x*x;
}

double dist(Point p, Point q, int v) {
    double x = p.x - q.x, y = p.y - q.y;
    return sqrt(sqr(x/3) + sqr(y/3)) / v;
}




void work() {
    scanf("%d%d", &n, &u);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }


    int AR = 0;
    Point cmax;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (area(a[i], a[j], a[k]) == 0) continue;
                int tmp = area(a[i], a[j], a[k]);
                if (tmp > AR) {
                    AR = tmp;
                    cmax = center(a[i], a[j], a[k]);
                } else if (tmp == AR) {
                    Point c = center(a[i], a[j], a[k]);
                    if (c.x > cmax.x) {
                        cmax = c;
                    } else if (c.x == cmax.x && c.y > cmax.y) {
                        cmax = c;
                    }
                }
            }
        }
    }



    AR = 2000000000;
    Point cmin;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (area(a[i], a[j], a[k]) == 0) continue;
                int tmp = area(a[i], a[j], a[k]);
                if (tmp < AR) {
                    AR = tmp;
                    cmin = center(a[i], a[j], a[k]);
                } else if (tmp == AR) {
                    Point c = center(a[i], a[j], a[k]);
                    if (c.x < cmin.x) {
                        cmin = c;
                    } else if (c.x == cmin.x && c.y < cmin.y) {
                        cmin = c;
                    }
                }
            }
        }
    }

    //printf("%lf %lf\n", cmax.x, cmax.y);
    //printf("%lf %lf\n", cmin.x, cmin.y);

    printf("%.2lf\n", dist(cmax, cmin, u)/2);
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//#endif
    int TestCase = 1;
    scanf("%d", &TestCase);
    while (TestCase --) {
        work();
    }
    return 0;
}
