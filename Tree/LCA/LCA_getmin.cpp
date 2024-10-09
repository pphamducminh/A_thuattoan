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
const long long MODD=111539786; // 998244353
const int maxN=1e5+9;
const short LOG=18;


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
vector<pair<int,int>> a[200009];

int luu[200009], dep[200009];

// LCA

long long p[22][200009], mn[22][200009];

void DFS(int u){
    for (int i=0; i<a[u].size(); i++){

        int v=a[u][i].first;
        if (p[0][u] != v){
            p[0][v]=u;
            mn[0][v]=a[u][i].second;
            dep[v]=dep[u]+1;
            luu[v]=luu[u]+a[u][i].second;
            for (int i=1; i<=LOG; i++){
                p[i][v]= p[i-1][p[i-1][v]];
                mn[i][v]=min(mn[i-1][v],mn[i-1][p[i-1][v]]);
            }
            DFS(v);
        }
    }
}




int LCA(int u, int v){


    if (dep[u]<dep[v]) swap(u,v);

    int diff=dep[u]-dep[v];
    for (int i=0; i<=LOG; i++){
        if ((diff>>i) & 1){
            u=p[i][u];
        } 
    }
    // cout << u << ' ' << v << "\n";

    if (u==v) return u;




    for (int i=LOG; i>=0; i--){
        if (p[i][u]!=p[i][v]){
            u=p[i][u];
            v=p[i][v];
        }
    }




    return p[0][u];


}

int getmin(int u, int v){

    if (dep[u]<dep[v]) swap(u,v);

    // cout << u << ' ' << v << "\n";


    long long ans=INF;

    for (int i=LOG; i>=0; --i) {
        if (dep[p[i][u]] >= dep[v]) ans=min(ans, mn[i][u]), u=p[i][u];
    }




    // cout << u << ' ' << v << "\n";

    if (u==v) return ans;




    for (int i=LOG; i>=0; i--){
        if (p[i][u]!=p[i][v]){
            ans=min(ans,min(mn[i][u],mn[i][v]));
            u=p[i][u];
            v=p[i][v];
        }
    }

    // cout << u << ' ' << v << ' ' << mn[0][u] << ' ' << mn[0][v] << "\n";




    return min({ans,mn[0][u],mn[0][v]});

}

int lifting(int u, int k){
    for (int i=0; i<=LOG; i++){
        if ((k>>i) & 1){
            u=p[i][u];
        }
    }

    return u;
}


void solve() {



    cin >> n;
    for (int i=1; i<n; i++){
        int x,y, mm;
        cin >> x >> y >> mm;

        a[x].push_back({y,mm});
        a[y].push_back({x,mm});



    }

    DFS(1);
    dep[0]=-1;
    // cout << LCA(3,2) << "\n";
    // cout << getmin(5,4) << "\n";    
    cout << getmin(1,3) << "\n";
    // cout << mn[0][3] << "\n";











}


// 1 2
// 1 2 
// 2 3 
// 3 4














