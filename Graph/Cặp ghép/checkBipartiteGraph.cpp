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


// kiem tra do thi 2 phia (đồ thị lưỡng phân)

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
const int maxN=1e6+9;
const short LOG=19;


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

int n,m;
vector<int> a[200009];
int color[200009];


bool checkBipartiteGraph(int x){
    queue<int> q;
    q.push(x);


    color[x]=0;
    while (!q.empty()){
        int u=q.front(); q.pop();

        for (int v: a[u]){
            if (color[v]==-1){
                color[v]=color[u]^1;
                q.push(v);
            }
            else if (color[v]==color[u]) return false;
        }
    }

    return true;
}
void solve(){

    
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    memset(color, -1, sizeof color);
    int ok=true;
    for (int i=1; i<=n; i++){
        if (color[i]==-1){
            if (!checkBipartiteGraph(i)){
                ok=false; break;
            }
        }
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";



}











