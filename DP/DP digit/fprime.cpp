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

bool nt[1000009];
string l,r;
int x[10009];
long long dp[1001][9001];

void add(long long &a, long long b){
    a+=b;
    while (a>=MOD) a-=MOD;
}

void sang(int n){
    nt[1]=1; nt[0]=1;
    for (int i=2; i*i<=n; i++){
        if (nt[i]) continue;
        for (int j=i*i; j<=n; j+=i){
            nt[j]=1;
        }
    }
}
bool check(string x){
    int sum=0;
    for (int i=0; i<x.length(); i++){
        if (x[i]=='3') return false;
        sum+=(x[i]-'0');
    }

    return !nt[sum];
}

long long try1(int pos, bool op, int sum){
    if (pos<0) return !nt[sum];


    if (op && dp[pos][sum]>=0) return dp[pos][sum];
    long long memo=0;

    int lim=(op?9:x[pos]);

    for (int d=0; d<=lim; d++){
        if (d==3) continue;
        add(memo,try1(pos-1,op || (d<lim),sum+d));
    }
    if (!op) return memo;
    else return dp[pos][sum]=memo;
}
long long calc(string s){
    int n=0; x[n]=0;
    for (int i=s.length()-1; i>=0; i--){
        x[n++]=s[i]-'0';
    }
    return try1(n-1,0,0);
}
void solve(){
    int t;
    cin >> t;

    sang(9000);
    memset(dp,-1,sizeof dp);
    while (t--) {
        cin >> l >> r;
        long long ans=0;


        // cout << calc(l) << "\n";
        cout << ((calc(r)-calc(l)+MOD*MOD)%MOD+check(l)%MOD)%MOD << "\n";
    }
}



