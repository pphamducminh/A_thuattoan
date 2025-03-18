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
 
 
 
const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD[] = {(long long)998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=3e5+9;
const long long LOG=17;
const double eps = 1e-5;
 
 
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
vector<int> a[1000009];
long long fac[1000009], dp[1000009], sz[1000009];
long long mul=1;



long long binpow(long long a, long long b){
 
    long long ans=1;
 
    while (b){
        if (b&1) ans=(ans*a)%MOD;
 
        a=(a*a)%MOD;
        b>>=1;
    }
 
    return ans;
}

void genfac(int n){
    fac[0]=1;
    for (long long i=1; i<=n; i++){
        fac[i]=fac[i-1]*i%MOD;
    }
}
void dfs(int u, int par){
    sz[u]=1;
    for (int x: a[u]){
        if (x==par) continue;

        dfs(x,u);
        sz[u]+=sz[x];
    }
    (mul*=sz[u])%=MOD;
}
void rerooting(int u, int par){
    for (int x: a[u]){
        if (x==par) continue;
        dp[x]=dp[u]*sz[x]%MOD*binpow(n-sz[x],MOD-2)%MOD;

        rerooting(x,u);
    }
}
void solve(){   
    cin >> n;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    genfac(n+1);
    dfs(1,1);
    dp[1]=fac[n]*binpow(mul,MOD-2)%MOD;

    rerooting(1,1);
    for (int i=1; i<=n; i++){
        cout << dp[i] << "\n";
    }
}
 
 



