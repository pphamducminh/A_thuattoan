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

// tim cap ghep cuc dai tren do thi 2 phia (đồ thị lưỡng phân)

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

int d=0;
int n,m,k;
vector<int> a[200009];
int luu[200009], match[200009];


bool bfs(){
    queue<int> q;


    //  check alternating path 
    for (int i=1; i<=n; i++){
        if (!match[i]) {
            q.push(i);
            luu[i]=0;
        }
        else luu[i]=INF;
    }

    // dinh 0 dai dien cho nhung dinh chua duoc ghep
    luu[0]=INF;

    while (!q.empty()){
        int u=q.front(); q.pop();

        if (luu[u]>=luu[0]) continue;

        for (int x: a[u]){
            if (luu[match[x]]==INF){
                q.push(match[x]);
                luu[match[x]]=luu[u]+1;
            }
        }


    }


    return luu[0]!=INF;

}

bool dfs(int u){
    // dinh 0 dai dien cho nhung dinh chua duoc ghep
    if (u==0) return true;
    for (int x: a[u]){
        if (luu[match[x]]==luu[u]+1 && dfs(match[x])){
            match[x]=u;
            match[u]=x;
            return true;
        }
    }

    luu[u]=INF;
    return false;
}

int hopcroft_karp(){

    int ans=0;

    while (bfs()){
        for (int u=1; u<=n; u++){
            // an augmenting path
            if (!match[u] && dfs(u)) ans++;
        }
    }

    return ans;
}

void solve(){


    cin >> n >> m >> k;

    for (int i=1; i<=n; i++){
        a[i].clear();
    }
    memset(luu,0,sizeof luu);
    memset(match,0,sizeof match);
    for(int i=1; i<=k; i++){
        int u,v;
        cin >> u >> v;
        v+=n;

        a[u].push_back(v);
        a[v].push_back(u);
    }



    cout << hopcroft_karp() << "\n";
    for (int i=1; i<=n; i++){
        if (match[i]) cout << i << ' ' << match[i]-n << "\n";
    }


}











