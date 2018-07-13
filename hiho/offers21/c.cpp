#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-7;
struct point2d{
    double x, y;
    point2d() {}
    point2d(double _x, double _y):x(_x),y(_y){}
};
struct line2d {
    point2d a, b;
    line2d() {}
    line2d(point2d _a, point2d _b):a(_a),b(_b){}
};
int N, M, K, Q;
point2d X[5], Xs, Xt;
vector<point2d> p;
vector<line2d> l;
int n;
vector<int> E[200];
bool Ret, f[200];

bool operator == (const point2d &a, const point2d &b) {
    return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
}

point2d operator - (const point2d &a, const point2d &b) {
    return point2d(a.x - b.x, a.y - b.y);
}

double det2d(const point2d &a, const point2d &b) {
    return a.x * b.y - a.y * b.x;
}

bool check_lineXline(const line2d &p, const line2d &q) {
    if (det2d(q.a - p.a, p.b - p.a) * det2d(p.b - p.a, q.b - p.a) <= eps) return false;
    if (det2d(p.a - q.a, q.b - q.a) * det2d(q.b - q.a, p.b - q.a) <= eps) return false;
    return true;
}

point2d lineXline(const point2d &a, const point2d &b,
                  const point2d &c, const point2d &d) {
}

void input_data()
{
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for (int i = 0; i <= Q; i ++) {
        scanf("%lf%lf", &X[i].x, &X[i].y);
    }
    scanf("%lf%lf", &Xs.x, &Xs.y);
    scanf("%lf%lf", &Xt.x, &Xt.y);
}

bool check_in(const point2d &a, const point2d &b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y) < K;
}

void add_point2d(const point2d &a) {
    for (int i = 0; i < p.size(); i ++) {
        if (p[i] == a) return;
    }
    p.push_back(a);
}

bool check_line(const line2d &p) {
    for (int i = 0; i < l.size(); i ++) {
        if (check_lineXline(p, l[i])) return false;
    }
    return true;
}

void dfs(int i) {
    f[i] = true;
    for (int j = 0; j < E[i].size(); j ++) {
        if (!f[E[i][j]]) {
            dfs(E[i][j]);
        }
    }
}

void solve()
{
    Ret = false;
    for (int i = 0; i <= Q; i ++) {
        if (check_in(Xs, X[i])) return;
        if (check_in(Xt, X[i])) return;
    }
    p.clear();
    l.clear();
    add_point2d(Xs);
    add_point2d(Xt);
    for (int i = 0; i <= Q; i ++) {
        add_point2d(point2d(X[i].x - K, X[i].y));
        add_point2d(point2d(X[i].x + K, X[i].y));
        add_point2d(point2d(X[i].x, X[i].y - K));
        add_point2d(point2d(X[i].x, X[i].y + K));
        l.push_back(line2d(point2d(X[i].x - K, X[i].y), point2d(X[i].x, X[i].y - K)));
        l.push_back(line2d(point2d(X[i].x - K, X[i].y), point2d(X[i].x, X[i].y + K)));
        l.push_back(line2d(point2d(X[i].x + K, X[i].y), point2d(X[i].x, X[i].y - K)));
        l.push_back(line2d(point2d(X[i].x + K, X[i].y), point2d(X[i].x, X[i].y + K)));
    }
    n = p.size();
    for (int i = 0; i < n; i ++) {
        E[i].clear();
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (check_line(line2d(p[i], p[j]))) {
                E[i].push_back(j);
                E[j].push_back(i);
                //printf("%d %d\n", i, j);
            }
        }
    }
    memset(f, false, sizeof(f));
    dfs(0);
    Ret = f[1];
}

void output_result()
{
    if (Ret) printf("Yes\n");
        else printf("No\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int Test = 1;
    scanf("%d", &Test);
    while (Test --) {
        input_data();
        solve();
        output_result();
    }
    return 0;
}

