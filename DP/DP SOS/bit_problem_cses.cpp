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
// #pragma GCC optimize("Ofast","inline","no-stack-protector")


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
const short LOG=20;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("creature");



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


long long dp1[1<<(LOG+2)], dp2[1<<(LOG+2)];
long long a[200009];
void solve(){

    int n;
    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> a[i];

        dp1[a[i]]++;
        dp2[a[i]]++;
    }


    for (int i=0; i<=LOG; i++){
        for (int mask=0; mask<(1<<LOG); mask++){
            if ((mask>>i)&1) dp1[mask]+=dp1[mask^(1<<i)];
            else dp2[mask]+=dp2[mask^(1<<i)];
        }
    }

    long long sum=(1<<LOG)-1;
    for (int i=1; i<=n; i++){
        // x|y==x   ->  y se la mask con cua x
        // x&y==x   ->  x se la mask con cua y
        // x&y!=0   ->  lay nhung thang mask con cua mask nguoc cua x, va tru di nhung thang do ra khoi kq 
        cout << dp1[a[i]] << ' ' << dp2[a[i]] << ' ' << n-dp1[sum^a[i]] << "\n";


    }



}










