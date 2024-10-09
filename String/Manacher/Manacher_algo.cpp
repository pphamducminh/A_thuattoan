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
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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
const int maxN=2e5+9;
const short LOG=19;


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



int dp[1009][1009], dpo[1000009], dpe[1000009];
string s;
int n;

void calc_odd(){

    int l=1, r=0;

    for (int i=1; i<=n; i++){
        if (i>r) dpo[i]=0;
        else dpo[i]=min(dpo[l+(r-i)], r-i);

        while (i-dpo[i]-1>0 && i+dpo[i]+1<=n && s[i-dpo[i]-1]==s[i+dpo[i]+1]) dpo[i]++;


        if (i+dpo[i] > r) {
            r=i+dpo[i];
            l=i-dpo[i];
        }

        // cout << i << ' ' << l << ' ' << r << "\n";
    }
}

void calc_even(){

    int l=1, r=0;

    for (int i=1; i<n; i++){
        int j=i+1;
        if (j>r) dpe[i]=0;
        else dpe[i]=min(dpe[l+(r-j)], r-j+1);

        while (i-dpe[i]>0 && j+dpe[i]<=n && s[i-dpe[i]]==s[j+dpe[i]]) dpe[i]++;


        if (i+dpe[i] > r) {
            r=i+dpe[i];
            l=j-dpe[i];
        }

        // cout << i << ' ' << l << ' ' << r << "\n";
    }
}
void solve() {
    



    
    cin >> s;

    n=s.length();

    s=' '+s;

    // for (int i=1; i<=n; i++){
    //     dp[i][i]=1;

    //     if (i<n && s[i]==s[i+1]) dp[i][i+1]=1;
    // }

    // for (int len=3; len<=n; len++){
    //     for (int i=1; i<=n-len+1; i++){
    //         int j=i+len-1;
    //         if (s[i]==s[j]){
    //             dp[i][j]=dp[i+1][j-1];
    //         }
    //         else dp[i][j]=0;
    //     }

    // }

    calc_odd();
    calc_even();


    // for (int i=1; i<=n; i++){
    //     cout << i << ' ' << p[i] << "\n";
    // }


    for (int i=1; i<n; i++){
        cout << dpo[i]*2+1 << ' ' << dpe[i]*2 << ' ';
    }
    cout << dpo[n]*2+1 << "\n";



}







