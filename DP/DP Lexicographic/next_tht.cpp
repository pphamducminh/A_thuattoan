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
const long long MODD[] = {(long long)220220061,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=2e5+9;
const long long LOG=50;
const double eps = 1e-7;


//------------------------


    
void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("IMPEVAL");



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

long long f[LOG+1][LOG+1];
long long gettttd(long long x, int k){
    long long ans=0;
    for (long long i=LOG-1; i>=0; i--){
        if ((x>>i)&1ll){
            ans+=f[i][k];
            k--;
        }
    }
    return ans+1;
}
long long getgt(long long tt, int k){
    long long ans=0;
    if (tt>f[LOG][k]) return -1;
    tt--;
    for (long long i=LOG-1; i>=0; i--){
        if (tt>=f[i][k]){
            tt-=f[i][k];
            // cout << i << ' ' << tt << "\n";
            k--;
            ans=ans+(1ll<<i);
            if (ans>1e15) return -1;
        }
    }
    return ans;
}
void solve(){

    f[0][0]=1;
    for (int i=1; i<=LOG; i++){
        for (int j=0; j<=i; j++){
            f[i][j]=f[i-1][j];

            if (j>0) f[i][j]+=f[i-1][j-1];
        }
    }




    int t;
    cin >> t;

    while (t--){
        long long x,k;
        cin >> x >> k;

        int sl=__builtin_popcountll(x);

        long long tt=gettttd(x,sl);

        long long ans=getgt(tt+k,sl);

        cout << ans << "\n";
    }

}


