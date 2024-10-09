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



// https://oj.vnoi.info/problem/mmmgame


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
const int maxN=1e5+9;
const short LOG=30;


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



void solve() {

    int q;
    cin >> q;

    while (q--){
        int n;
        cin >> n;

        int xr=0, d=0;
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;

            xr^=x;

            if (x<2) d++;
        }

        if (d==n){
            if (d%2==0) cout << "John\n"; else cout << "Brother\n";
        }
        else{
            if (xr) cout << "John\n"; else cout << "Brother\n";
        }
    }

}
