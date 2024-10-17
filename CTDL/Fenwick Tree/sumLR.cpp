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


int n;
int bit[1000009];
void update(int u, int v){
    for(; u > 0; u -= u & -u) bit[u] += v;
}

int get(int u){
    int res = 0;
    for(; u <= n; u += u & -u) res += bit[u];
    return res;
}
void solve() {


    
    cin >> n;

    string s;
    cin >> s;

    // for (int i=1; i<=n; i++){
    //     update(i,1);
    // }
    

    update(3,1);
    update(4,1);
    cout << get(5) << "\n";



}
