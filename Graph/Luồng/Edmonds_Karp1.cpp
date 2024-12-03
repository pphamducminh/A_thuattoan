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






using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD=111539786; // 998244353
const int maxN=509;
const short LOG=18;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("moji");



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

long long max_flow(vector<vector<int>> a, vector<vector<long long>> capacity,
                   int s, int t) {
    int n = a.size();
    vector<int> truoc(n, -1);


    auto bfs = [&]() -> bool {
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto son : a[v]) {
                long long w = capacity[v][son];
                if (w <= 0 || truoc[son] != -1) continue;
                truoc[son] = v;
                q.push(son);
            }
        }
        return truoc[t] != -1;
    };

    long long flow = 0;


    while (bfs()) {
        int v = t;


        long long curr_flow = INF;
        while (v != s) {
            curr_flow = min(curr_flow, capacity[truoc[v]][v]);
            v = truoc[v];
        }
        v = t;
        while (v != s) {

            capacity[truoc[v]][v] -= curr_flow;

            capacity[v][truoc[v]] += curr_flow;
            v = truoc[v];
        }
        flow += curr_flow;
        fill(truoc.begin(), truoc.end(), -1);
    }

    return flow;
}
void solve() {

    
    cin >> n >> m;


    vector<vector<long long>> capacity(n, vector<long long>(n, 0));
    vector<vector<int>> a(n);
    for (int i=1; i<=m; i++){
        int u,v,c;
        cin >> u >> v >> c;

        u--; v--;

        // cout << u << ' ' << v << "\n";

        a[u].push_back(v);
        a[v].push_back(u);
        capacity[u][v] += c;
    }

    cout << max_flow(a, capacity, 0, n - 1) << "\n";
}









