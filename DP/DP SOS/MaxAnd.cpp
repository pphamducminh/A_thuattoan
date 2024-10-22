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

const long long INF=3e18+3;
const long long MOD=1e9+7;
const long long MODD=111539786; // 998244353
const int maxN=1e6+9;
const short LOG=20;


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



long long a[1000009];
int n;

namespace sub1{
    void solve(){

        sort(a+1,a+n+1);

        long long ansmain=0;
        do {
            long long ans=0,tam=a[1];
            ans+=tam;
            for (int i=2; i<=n; i++){
                tam&=a[i];
                ans+=tam;
            }
            ansmain=max(ans,ansmain);



            

        }while (next_permutation(a+1,a+n+1));


        cout << ansmain;
        exit(0);
    }
}


namespace sub2{

    bool check(){
        for (int i=1; i<=n; i++){
            if (__builtin_popcount(a[i])>1) return false;
        }
        return true;
    }

    long long mm[1000009];
    void solve(){

        long long mx=0;
        for (int i=1; i<=n; i++){
            mm[a[i]]++;
        }

        for (int i=1; i<=n; i++){
            mx=max(mx,a[i]*mm[a[i]]);
        }

        cout << mx;

        exit(0);
    }
}


long long mm[(1<<LOG)+1], dp[(1<<LOG)+1];
vector<int> luu[1000009];

bool cmp(int aa, int bb){
    if (aa==bb) return __builtin_popcount(aa) > __builtin_popcount(bb);
    return aa>bb;
}
void solve() {

    



    cin >> n;


    for (int i=1; i<=n; i++){
        cin >> a[i];
    }



    if (n<=10) sub1::solve();
    if (sub2::check()) sub2::solve();



    // sort(a+1,a+n+1,cmp);




    // long long ans=0,tam=a[1];
    // ans+=tam;
    // for (int i=2; i<=n; i++){
    //     tam&=a[i];
    //     ans+=tam;
    // }



    // cout << ans;



    // for (int i=1; i<=n; i++){

    //     for (int j=LOG-1; j>=0; j--){
    //         if ((a[i]>>j)&1) mm[j]++, luu[j].push_back(i);
    //     }

    // }

    // int pos=0, mx=0;
    // for (int i=LOG-1; i>=0; i--){
    //     if (mm[i]>mx){
    //         mx=mm[i]; pos=i;
    //     }

    //     mm1[i]=1;
    // }


    // sort(all(luu[pos]), cmp);


    // vector<int> ans;


    // for (int i=0; i<luu[pos].size(); i++){
    //     ans.push_back(a[luu[pos][i]]);


    //     int x=a[luu[pos][i]];

    //     for (int j=)
    // }




    for (int i=1; i<=n; i++){
        mm[a[i]]++;
    }

    for (int i=0; i<LOG; i++){
        for (int mask=(1<<LOG)-1; mask>=0; mask--){
            if (!((mask>>i)&1)) mm[mask]+=mm[mask^(1<<i)];
        }
    }


    // for (int mask=0; mask<(1<<LOG); mask++){
    //     cout << mask << ' ' << mm[mask] << "\n";
    // }


    memset(dp,0,sizeof dp);

    for (int mask=1; mask<(1<<LOG); mask++){
        for (int i=0; i<LOG; i++){
            if ((mask>>i)&1){
                dp[mask]=max(dp[mask],dp[mask^(1<<i)] + mm[mask]*(1<<i));
            }

        }
    }

    long long ans=0;
    for (int mask=0; mask<(1<<LOG); mask++){
        ans=max(ans,dp[mask]);
    }
    cout << ans;


}


// 1 2
// 1 2 
// 2 3 
// 3 4















