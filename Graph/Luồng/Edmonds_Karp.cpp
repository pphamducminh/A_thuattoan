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

const long long INF=1e18;
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
// vector<vector<int>> capacity;
vector<int> a[1009];
long long capacity[1009][1009];

long long bfs(int s, int t, vector<int>& truoc) {
    fill(truoc.begin(), truoc.end(), -1);
    truoc[s] = -2;
    queue<pair<int, long long>> q;
    q.push({s, INF});



    while (!q.empty()) {
        int cur = q.front().first;
        long long flow = q.front().second;
        q.pop();

        for (int x : a[cur]) {
            if (truoc[x] == -1 && capacity[cur][x]) {
                truoc[x] = cur;
                long long new_flow = min(flow, capacity[cur][x]);
                if (x == t)
                    return new_flow;
                q.push({x, new_flow});
            }
        }
    }

    return 0;
}

long long maxflow(int s, int t) {
    long long flow = 0;
    vector<int> truoc(n);
    long long new_flow;

    while (new_flow = bfs(s, t, truoc)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = truoc[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve() {

    
    cin >> n >> m;

    for (int i=1; i<=m; i++){
        long long u,v,c;
        cin >> u >> v >> c;

        u--; v--;

        // cout << u << ' ' << v << "\n";

        a[u].push_back(v);
        a[v].push_back(u);
        capacity[u][v] += c;
    }

    cout << maxflow(0,n-1) << "\n";
}









