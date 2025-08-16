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

int d;
string s;
int x[10009];
long long dp[10009][2][102];

void add(long long &a, long long b){
    a+=b;
    while (a>=MOD) a-=MOD;
}
long long calc(string s){
    int n=s.length();
    for (int i=0; i<=n; i++){
        for (int op=0; op<=1; op++){
            for (int mod=0; mod<=d; mod++){
                dp[i][op][mod]=0;
            }
        }
    }    

    dp[n][1][0]=dp[n][0][0]=1;
    for (int i=n-1; i>=0; i--){
        for (int op=0; op<=1; op++){
            for (int mod=0; mod<=d; mod++){
                if (op){
                    for (int c=0; c<=(s[i]-'0'); c++){
                        add(dp[i][op][mod],((c==s[i]-'0') ? dp[i+1][1][(mod+c)%d] : dp[i+1][0][(mod+c)%d]));
                    }
                }
                else{
                    for (int c=0; c<=9; c++){
                        add(dp[i][op][mod],dp[i+1][0][(mod+c)%d]);
                    }
                }
            }
        }
    }

    return (dp[0][1][0]-1+MOD*MOD)%MOD;
}
void solve(){
    cin >> s >> d;

    cout << calc(s);
}



