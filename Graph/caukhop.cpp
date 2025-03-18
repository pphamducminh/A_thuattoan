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
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC optimize("Ofast","inline","no-stack-protector")
// #pragma GCC target("arch=skylake")


using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e18;
const long long MOD=1e9+7;
const long long MODD[] = {998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=1e6+9;
const long long LOG=18;
const double eps = 1e-6;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("CARNAVAL");



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

vector<int> a[200009];

int ti=0, low[200009], num[200009], bridge=0, ver=0, p=0,n,m; 
void tarjan(int u, int par){

    low[u]=num[u]=++ti;

    int ver=(par!=0);

    for (int x: a[u]){

        if (x==par) continue;


        // if (removed[x]) continue;

        if (!num[x]){

            tarjan(x,u);
            low[u]=min(low[u],low[x]);

            if (low[x]>=num[u]) ver++;
            if (low[x]==num[x]) bridge++;
        }
        else low[u]=min(low[u],num[x]);
    }
    
    p+=(ver>=2);

}

void solve(){
    cin >> n >> m;

    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i=1; i<=n; i++){
        if (!num[i]) tarjan(i,0);
    }

    cout << p << ' ' << bridge << "\n";
}
