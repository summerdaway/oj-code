#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(const T &t, const char &eol = '\n') {
    cout << t << eol;
}

template<typename T, typename ...Args>
void print(const T &t, const Args &...rest) {
    cout << t << ' ';
    print(rest...);
}
const int N =1e5+5;


vector<int> g[N];
bool vis[N];
int n;
int max_size, centroid;
set<int> V;

// TODO: better (shorter) implementation of get_centroid
int get_centroid(int u, int f){
    int size = 1;
    int ma = 0;
    V.insert(u);
    for(auto v: g[u]){
        if(v!=f && !vis[v]){
            int t = get_centroid(v, u);
            ma = max(ma, t);
            size += t;
        }
    }
    ma = max(ma, n - size);
    if(ma < max_size){
        max_size = ma;
        centroid = u;
    }
    return size;
}




long long sum;

long long calc(int x){
    return 1LL*x*(x+1)/2;
}

void stats(){   //stats: 统计
    /* 示意图
     * 00011110000111
     */
    // 注意思考循环不变量!
    //l1:当前集合中的连续段的左端点
    //l2:当前集合的补集中的连续段的左端点
    int l1=1, l2 = 1; // 这个双指针要好好总结!太美妙了!
    for(auto x: V){
        if(x==l2){
            ++l2;
        }
        else{
            // 用左闭右开的方法表示区间有很大的优越性
            sum += calc(x - l2);
            sum += calc(l2 - l1);
            l2 = x + 1;
            l1 = x;
        }
    }
    sum += calc(n+1 - l2);
    sum += calc(l2 - l1);
}

// dc: dive and conquer
void solve(int u, int f){
    max_size = INT_MAX;
    V.clear();
    get_centroid(u, u);
//    print("centroid", centroid);
    vis[centroid] = true;

    // 前序!
    if(u!=f) stats(); // 对每条边统计一次!

    for(auto v: g[centroid]){
        if(!vis[v]){
            solve(v, centroid);
        }
    }
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//////////////////////////////////////////////////////
// 为何我的代码写得如此啰嗦？
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve(1, 1);
    print((n-1)*calc(n)-sum);
    return 0;
}