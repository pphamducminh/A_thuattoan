#include <iostream>
#include <bits/stdc++.h>
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
const long long MODD[] = {998244353,(int)1e9+2277, (int)1e9+5277}; // 998244353
const int maxN=2e5+9;
const long long LOG=18;
const double eps = 1e-7;
 
 
//------------------------
 
 
 
void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif
 
    // file("XN2NTQ");
 
 
 
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
long long phi[1000009],g[1000009],pre[1000009];
void prephi(int n) {
    for (int i=0; i<=n; i++){
        phi[i]=i;
    }
    for (long long i=2; i<=n; i++){
        if (phi[i]!=i) continue;
        for (long long j=i; j<=n; j+=i){
            phi[j]-=phi[j]/i;
        }
    }
}
void prepro(int n){
    prephi(n);     
 
    for (int i=1; i<=n; i++){
        pre[i]=pre[i-1]+phi[i];
    }
}
 
long long calc(int n){
    int lim=n;
 
    long long ans=0;
    int l=2;
    while (l<=lim) {
        long long n1=n/l;
 
        int r1=n/n1;
 
        int r=min(r1,lim);
        ans+=(pre[r]-pre[l-1])*(n1*(n1+1)/2);
        l=r+1;
    }
    return ans;
}
void solve() { 
    prepro(1e6+2);
    while (cin >> n){
        if (n==0) break;
        cout << calc(n) << "\n";
    }
}