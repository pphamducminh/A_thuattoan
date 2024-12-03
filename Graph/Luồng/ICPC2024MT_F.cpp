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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("Ofast","inline","no-stack-protector")


using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD=998244353; // 998244353
const int maxN=1e6+9;
const short LOG=18;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("creature");



    int t;

    cin >> t;

    // t=1;

    while (t--){
        solve();
    }

    cerr << "Time: " << TIME << "s.\n";
    cerr << "ducminh";
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------







struct Edge {
    int s, w, flow, rev;
};

class Dinic {
public:
    vector<Edge> adj[10005];
    int level[10005];
    int ptr[10005];
    
    void add_edge(int from, int s, int w) {
        Edge a = {s, w, 0, (int)adj[s].size()};
        Edge b = {from, 0, 0, (int)adj[from].size()};
        adj[from].push_back(a);
        adj[s].push_back(b);
    }

    bool bfs(int s, int t) {
        memset(level, -1, sizeof(level));
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (const Edge &edge : adj[cur]) {
                if (level[edge.s] == -1 && edge.flow < edge.w) {
                    level[edge.s] = level[cur] + 1;
                    q.push(edge.s);
                    if (edge.s == t) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int dfs(int cur, int t, int flow) {
        if (cur == t) {
            return flow;
        }
        for (; ptr[cur] < adj[cur].size(); ++ptr[cur]) {
            Edge &edge = adj[cur][ptr[cur]];

            if (level[edge.s] == level[cur] + 1 && edge.flow < edge.w) {
                int new_flow = min(flow, edge.w - edge.flow);
                int pushed = dfs(edge.s, t, new_flow);

                if (pushed > 0) {
                    edge.flow += pushed;
                    adj[edge.s][edge.rev].flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            memset(ptr, 0, sizeof(ptr));
            while (int flow = dfs(s, t, INF)) {
                ans += flow;
            }
        }
        return ans;
    }
};

void solve(){

    int n;
    int amx, bmx, cmx;
    cin >> n >> amx >> bmx >> cmx;

    Dinic A;

    int s=0, t=n+4;  
    int anode=n + 1, bnode=n + 2, cnode=n + 3;


    int k, x;
    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> x;
        A.add_edge(x, anode, 1); 
    }


    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> x;
        A.add_edge(x, bnode, 1);
    }


    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> x;
        A.add_edge(x, cnode, 1);
    }


    for (int i=1; i<=n; i++) {
        A.add_edge(s, i, 1);
    }


    A.add_edge(anode, t, amx);
    A.add_edge(bnode, t, bmx);
    A.add_edge(cnode, t, cmx);


    int ans = A.max_flow(s, t);
    cout << ans << "\n";



}
