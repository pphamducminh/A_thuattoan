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
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("Ofast","inline","no-stack-protector")
// #pragma GCC target("arch=skylake")

using namespace std;


#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long



const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD[] = {(long long)220220061,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=1e5+9;
const long long LOG=18;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("PNUM");



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


int n;
vector<int> a[200009];

long long sz[200009], dp[200009];

void dfs(int u, int par){
    sz[u]=1;
    for (int x: a[u]){
        if (x==par) continue;

        dfs(x,u);
        sz[u]+=sz[x];
        dp[u]+=dp[x]+sz[x];
    }
}

void rerooting(int u, int par){
    for (int x: a[u]){
        if (x==par) continue;

        dp[x]=dp[u]-sz[x]+(n-sz[x]);
        rerooting(x,u);
    }
}
void solve(){  
    cin >> n;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;

        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    dfs(1,0);
    rerooting(1,0);

    for (int i=1; i<=n; i++){
        cout << dp[i] << "\n";
    }
}





