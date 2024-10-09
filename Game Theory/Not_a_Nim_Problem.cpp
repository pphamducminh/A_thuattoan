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


// https://codeforces.com/contest/2004/problem/E


using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD=111539786; // 998244353
const int maxN=5e5+9;
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


bool nt[10000009];
int f[10000009], p[10000009], d[10000009];

void sang(int n){


    nt[0]=true; nt[1]=true;

    int d=0;
    for (long long i=2; i<=n; i++){
        if (nt[i]) continue;

        p[i]=++d;
        for (long long j=i*i; j<=n; j+=i){
            nt[j]=true;
        }
    }
}


void solve() {



    // build gia tri Nim
    

    sang(1e7);


    // cout << p[13] << "\n";


    f[0]=0; f[1]=1;

    for (int i=2; i<=1e7; i++){
        for (int j=i; j<=1e7; j+=i){
            if (!nt[i] && !d[j]) d[j]=i;
        }
    }

    for (int i=3; i<=1e7; i+=2){
        if (!nt[i]){
            f[i]=p[i];
        }
        else f[i]=f[d[i]];
    }


    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        int xr=0;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;

            xr^=f[x];
        }



        if (xr) cout << "Alice\n";
        else cout << "Bob\n";
    }




}



