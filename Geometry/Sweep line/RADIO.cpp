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

// a thai - VOI 24

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
const short LOG=19;


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

#define int ll

int n;
pair<int,int> l[maxN], r[maxN];

int t[maxN], dp[maxN];
vector<int> in[maxN], out[maxN];


long long tree[maxN*4],lz[maxN*4];




void down(int id, int l, int r){


    if (!lz[id]) return;

    tree[id]=((r-l+1)*lz[id]);
    if (l!=r) lz[id*2]=lz[id*2+1]=lz[id];

    lz[id]=0;
}

void buildtree(long long id, long long l, long long r){

    if (l==r){

        tree[id]=INF;
        lz[id]=INF;
        // cout << id << "\n";
        return;
    }

    long long m=(l+r)>>1;

    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id]=min(tree[id*2],tree[id*2+1]);
    lz[id]=min(lz[id*2],lz[id*2+1]);

}


void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){


    // down(id,l,r);


    if (u>r || v<l) return;

    if (l==r){
        
        tree[id]=val;
        // lz[id]=val;
        // down(id,l,r);
        // tree[id]=(r-l+1)-tree[id];
        // if (tree[id]==0) tree[id]=1;
        // else tree[id]=0;
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r << "\n";

        return;
    
    }

    long long m=(l+r)>>1;

    updatetree(id*2,l,m,u,v, val);
    updatetree(id*2+1,m+1,r,u,v, val);

    tree[id]=min(tree[id*2],tree[id*2+1]);


}



long long gettree(long long id, long long l, long long r, long long u, long long v){

    // down(id,l,r);

    if (u>r || v<l) return INF;

    if (u<=l && r<=v) return tree[id];

    long long m=(l+r)>>1;

    return min(gettree(id*2,l,m,u,v), gettree(id*2+1,m+1,r,u,v));
}


void solve() {




    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> t[i] >> l[i].first >> l[i].second >> r[i].first >> r[i].second;

        in[r[i].first].push_back(i);
        out[r[i].second].push_back(i);
    }


    memset(dp,0x3f,sizeof dp);
    dp[1]=0;
    buildtree(1,1,n);


    // sweep line i=1->n

    for (int i=1; i<=n; i++){
        for (int p: in[i]){
            updatetree(1,1,n,p,p,dp[p]-p+t[p]);
        }
    


        if (i!=1) dp[i]=gettree(1,1,n,l[i].first,l[i].second)+i+t[i];


        if (r[i].first<=i && i<=r[i].second) updatetree(1,1,n,i,i,dp[i]-i+t[i]);

        for (int p: out[i]){
            updatetree(1,1,n,p,p,INF);
        }
    


    }


    for (int i=2; i<=n; i++){
        if (dp[i]>=INF) cout << -1 << ' ';
        else cout << dp[i] << ' ';
    }


}


// 1 2
// 1 2 
// 2 3 
// 3 4















