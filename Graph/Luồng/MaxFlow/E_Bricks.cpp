#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <deque>
#include <random>
#include <sstream>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC optimize("Ofast","inline","no-stack-protector")

// https://codeforces.com/contest/1404/problem/E


using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e18;
const long long MOD=1e9+7;
const long long MODD=998244353; // 998244353
const int maxN=1e6+9;
const short LOG=20;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("boat");



    int t;

    // cin >> t;

    t=1;

    while (t--){
        solve();
    }

    cerr << "Time: " << TIME << "s.\n";
    cerr << "ducminh";
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------


int n,m;
char a[1009][209];

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> dscanh;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        dscanh.emplace_back(v, u, cap);
        dscanh.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (dscanh[id].cap - dscanh[id].flow < 1)
                    continue;
                if (level[dscanh[id].u] != -1)
                    continue;
                level[dscanh[id].u] = level[v] + 1;
                q.push(dscanh[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = dscanh[id].u;
            if (level[v] + 1 != level[u] || dscanh[id].cap - dscanh[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, dscanh[id].cap - dscanh[id].flow));
            if (tr == 0)
                continue;
            dscanh[id].flow += tr;
            dscanh[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

// Dinic A;


int id(int i, int j){
    return (i-1)*m+j;
}

void solve() {

    
    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }


    Dinic A(n*m+2,0,n*m+1);
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j]=='#') {
                if (a[i][j-1]=='#') A.add_edge(id(i,j),id(i,j-1),1);
                else A.add_edge(id(i,j),A.t,1);
                if (a[i-1][j]=='#') A.add_edge(id(i-1,j),id(i,j),1);
                else A.add_edge(A.s,id(i,j),1);
            }
        }
    }
    cout << A.flow() << "\n";
}









