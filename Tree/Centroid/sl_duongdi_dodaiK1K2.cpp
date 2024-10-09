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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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
const int maxN=2e5+9;
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

    // scanf("%d", &t);

    t=1;

    while (t--){
        solve();
    }

    cerr << "Time: " << TIME << "s.\n";
    cerr << "ducminh";
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------


int n, k, k1, k2;
long long ans=0, sum[maxN];
vector<int> a[maxN];




struct fenwick_tree {
    int cnt[maxN];

    int gettree(int so){

        if (so <= 0) return 0;

        int res = 0;

        while (so){

            res += cnt[so];
            so -= (so & (- so));

        }

        return res;

    }

    void updatetree(int so, int v){

        while (so <= k2){

            cnt[so] += v;
            so += (so & (- so));

        }

    }

};

fenwick_tree fenTree;



struct CentroidDecomposition {

    int del[maxN],child[maxN], deep=0, dp[maxN];


    void init(){
        fill(dp,dp+n+1,0);
        fill(del,del+n+1,0);
        fill(child,child+n+1,0);

        dp[0]=1;
        // buildtree(1,0,n);
        // fenTree.updatetree(0,1);
    }


    void countChild(int u, int par){
        child[u]=1;
        for (int v: a[u]){
            if (v!=par && !del[v]){
                countChild(v,u);
                child[u]+=child[v];
            }
        }

    }

    int findCentroid(int u, int par, int n){

        for (int v: a[u]){
            if (v!=par){
                if (child[v]>n/2 && !del[v]){
                    return findCentroid(v,u,n);
                }
            }
        }

        return u;
    }

    void dfs(int u, int par, bool type, int d=1){

        if (d>k2) return;
        deep=max(deep,d);

        if (type) 
            fenTree.updatetree(d + 1, 1);
        else 
            ans += fenTree.gettree(min(n - 1, min(k2, n) - d) + 1) - fenTree.gettree(max(0, k1 - d));



        for (int v: a[u]){
            if (v!=par && !del[v]){
                dfs(v,u,type,d+1);
            }
        }

    }

    void solve(int u){
        countChild(u,0);

        int n=child[u];
        int root=findCentroid(u,0,n);


        if (n < k1) return;

        // dfs(root,n);

        del[root]=1;

        deep=0;
        fenTree.updatetree(1, 1);

        for (int v: a[root]){
            if (!del[v]){
                dfs(v,root,false);
                dfs(v,root,true);
            }
        }

        // buildtree(1,0,n);
        // updatetree(1,0,n,0,0,1);
        for (int i=1; i<=deep+1; i++){
            // updatetree(1,0,n,i,i,-gettree(1,0,n,i,i)+gettree(1,0,n,i-1,i-1));
            fenTree.updatetree(i,-fenTree.gettree(i));
        }
        // fill(dp+1, dp+deep+1, 0);

        for (int v: a[root]){
            if (!del[v]){
                solve(v);
            }
        }

        // return ans;
    }

} centroid;

void solve() {

    scanf("%d %d %d", &n, &k1, &k2);

    for (int i=1; i<n; i++){
        int x,y;
        scanf("%d %d", &x, &y);

        a[x].push_back(y);
        a[y].push_back(x);
    }

    centroid.init();
    centroid.solve(1);

    printf("%lld\n", ans);
}
