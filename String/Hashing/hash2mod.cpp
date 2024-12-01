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

const long long INF=1e18;
const long long MOD=1e9+7;
const long long MODD[] = {998244353,(int)1e9+2277, (int)1e9+5277}; // 998244353
const int maxN=2e5+9;
const long long LOG=256;
const double eps = 1e-6;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("kittens");



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



long long pbase[3][maxN],hashp=0, hs[3][maxN];
long long get(long long i,long long j, int op) {
    return (hs[op][j]+ MODD[op] - hs[op][i-1] * pbase[op][j - i + 1]) % MODD[op];
}
void solve(){


    string s;
    cin >> s;

    int sz=s.size();
    s=' '+s;

    pbase[1][0]=1;
    pbase[2][0]=1;

    for (int i=1; i<=sz; i++){
        pbase[1][i]=(pbase[1][i-1]*LOG)%MODD[1];
        pbase[2][i]=(pbase[2][i-1]*LOG)%MODD[2];
    }

    hs[1][0]=0;
    hs[2][0]=0;
    for (int i=1; i<=sz; i++){
        hs[1][i]=(hs[1][i-1]*LOG+s[i]-'a'+1)%MODD[1];
        hs[2][i]=(hs[2][i-1]*LOG+s[i]-'a'+1)%MODD[2];
    }


}
















