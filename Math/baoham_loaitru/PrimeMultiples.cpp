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



const long long INF=2e18;
const long long MOD=1e9+7;
const long long MODD[] = {(long long)998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=5e5+9;
const long long LOG=30;
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

// bai toan: cho 2 so nguyen n va r, hay dem so luong so i trong doan [1,r] sao cho i va n la coprime

long long n,k;
long long ans=0;
vector<long long> luu;
void solve(){
    cin >> n >> k;
    for (int i=1; i<=k; i++){
        long long x;
        cin >> x;

        luu.push_back(x);

    }




    for (int mask=1; mask<(1<<k); mask++){
        // if (__builtin_popcount(mask)<=1) continue;

        long long mul=1;
        for (int i=0; i<k; i++){
            if ((mask>>i)&1) {
                if (mul>=n/luu[i]+1) {mul=INF; break; }
                mul*=luu[i];
            }
        }


        long long sl=n/mul;
        if (__builtin_popcount(mask)&1) ans+=sl;
        else ans-=sl;
    }

    cout << ans;

}
 
 







