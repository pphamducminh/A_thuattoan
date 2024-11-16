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

const long long INF=1e18;
const long long MOD=1e9+7;
const long long MODD=998244353; // 998244353
const int maxN=2e5+9;
const short LOG=20;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("boxes");



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


pair<long long, long long> dp[1<<(LOG+1)];
long long a[29];
void solve(){

    int n,w;
    cin >> n >> w;

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int mask=0; mask<(1<<n); mask++){
        dp[mask]={INF,INF};
    }

    dp[0]={1,0};
    for (int mask=1; mask<(1<<n); mask++){
        for (int i=0; i<n; i++){
            if ((mask>>i)&1) {

                long long sl=dp[mask^(1<<i)].first;
                long long kl=dp[mask^(1<<i)].second;


                if (kl+a[i+1]>w){
                    sl++;
                    kl=a[i+1];
                }
                else kl+=a[i+1];

                dp[mask]=min(dp[mask],make_pair(sl,kl));
            }
        }
    }


    cout << dp[(1<<n)-1].first;



}
 
 
 







