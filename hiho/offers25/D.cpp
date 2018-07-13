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


    void print() {
        printf("%d %d %d %d\n", x1.x, x1.y, x2.x, x2.y);
    }
};

struct Polygon {
    Point p[20];
    Edge e[20];
    int es;
};

Edge Q[100];
Triangle T[10];
bool vt[10], ve[20];
int N, m, A, B, label[20];
vector<Polygon> po;

bool check(Edge e1, Edge e2) {
    return e1.x2 - e1.x1 == e2.x2 - e2.x1;
}

int cross_product(Point x1, Point x2) {
    return x1.x*x2.y - x1.y*x2.x;
}

bool check1(Edge e1, Edge e2) {
    if (e1.x2 == e2.x1 && cross_product(e1.x2 - e1.x1, e2.x1 - e2.x2) == 0) return true;
    return false;
}


bool hecheng(Polygon g1, Polygon g2, Polygon &t) {
    for (int i = 0; i < g1.es; ++i) {
        for (int j = 0; j < g2.es; ++j) {
            if (check(g1.e[i], g2.e[j])) {
                t.es = 0;
                Point diff = g2.e[j].x1 - g1.e[i].x1;
                printf("e1 = %d %d\n", g2.e[j].x1.x, g2.e[j].x1.y);
                printf("e2 = %d %d\n", g1.e[j].x1.x, g1.e[j].x1.y);
                for (int k = 0; k < g1.es; ++k) {
                    if (k != i) t.e[t.es++] = g1.e[k];
                }
                for (int k = 0; k < g2.es; ++k) {
                    if (k != j) {
                        t.e[t.es++] = Edge(g2.e[k].x1 - diff, g2.e[k].x2-diff);
                    }
                }
                for (i = 0; i < t.es; ++i) {
                    for (j = 0; j < t.es; ++j) {
                        if (i != j && check1(t.e[i], t.e[j])) {
                            t.e[i] = Edge(t.e[i].x1, t.e[j].x2);
                            swap(t.e[j], t.e[t.es-1]);
                            t.es--;
                            return true;
                        }
                    }
                }
                for (int i = 0; i < t.es; ++i) {
                    t.e[i].print();
                }

                return true;
            }
        }
    }
    return false;

}

bool paraX(Edge x) {
    Point t = x.x2 - x.x1;
    return t.y == 0;
}

bool paraY(Edge x) {
    Point t = x.x2 - x.x1;
    return t.x == 0;
}

bool checkrec(Polygon t) {
    if (t.es != 4) return false;
    int px, py;
    px = py = 0;
    for (int i = 0; i < 4; ++i) {
        px += paraX(t.e[i]);
        py += paraY(t.e[i]);
    }
    if (px != 2 || py != 2) return false;
    for (int i = 0; i < 4; ++i) {
        if (paraX(t.e[i]) && t.e[i].len() != A*A) return false;
        if (paraY(t.e[i]) && t.e[i].len() != B*B) return false;
    }
    return true;
}

bool dfs(vector<Polygon> p) {
    if (p.size() == 1) {
        for (int i = 0; i < p.size(); ++i) {
            for (int j = 0; j < p[i].es; ++j) {
                p[i].e[j].print();
            }
        }
        printf("-----------------\n");
        return checkrec(p[0]);
    }

    vector<Polygon> a;
    for (int i = 0; i < p.size(); ++i) {
        for (int j = i + 1; j < p.size(); ++j) {
            Polygon t;
            printf("i = %d j = %d\n", i, j);
            if (hecheng(p[i], p[j], t)) {

                a.clear();
                for (int k = 0; k < p.size(); ++k) {
                    if (k != i && k != j) {
                        a.push_back(p[k]);
                    }
                }
                a.push_back(t);
                if (dfs(a)) return true;
            }
        }
    }
    return false;
}

bool work() {

    scanf("%d%d%d", &N, &A, &B);
    for (int i = 0; i < N; ++i) {
        Polygon py;
        for (int j = 0; j < 3; ++j) {
            int x, y;
            scanf("%d%d", &x, &y);
            T[i].p[j] = Point(x, y);
            py.p[j] = Point(x, y);
        }
        for (int j = 0; j < 3; ++j) {
            //T[i].e[j] = Edge(T[i].p[j], T[i].p[(j+1)%3]);
            py.e[j] = Edge(T[i].p[j], T[i].p[(j+1)%3]);
        }
        py.es = 3;

        po.push_back(py);
    }


    return dfs(po);



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