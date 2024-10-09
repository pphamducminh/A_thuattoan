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

long long n, k;
long long ans=0, sum[maxN];
vector<pair<int,int>> a[maxN];



struct CentroidDecomposition {

    int del[maxN],child[maxN], deep=0, dp[maxN];


    void init(){
        // fill(dp,dp+n+1,INF);
        ans=INF;
        memset(dp, 0x3f, sizeof(dp));
        fill(del,del+n+1,0);
        fill(child,child+n+1,0);


    }


    void countChild(int u, int par){
        child[u]=1;
        for (pair<int,int> v: a[u]){
            if (v.first!=par && !del[v.first]){
                countChild(v.first,u);
                child[u]+=child[v.first];
            }
        }

    }

    int findCentroid(int u, int par, int n){

        for (pair<int,int> v: a[u]){
            if (v.first!=par){
                if (child[v.first]>n/2 && !del[v.first]){
                    return findCentroid(v.first,u,n);
                }
            }
        }

        return u;
    }

    void dfs(int u, int par, bool type, int d, int sumpath){

        if (d>k) return;
        deep=max(deep,d);

        if (type) dp[d]=min(dp[d],1LL*sumpath);
        else ans=min(ans,sumpath+dp[k-d]);



        for (pair<int,int> v: a[u]){
            if (v.first!=par && !del[v.first]){
                dfs(v.first,u,type,d+1,sumpath+v.second);
            }
        }

    }

    void solve(int u){
        countChild(u,0);

        int n=child[u];
        int root=findCentroid(u,0,n);

        // dfs(root,n);

        del[root]=1;

        deep=0;
        dp[0]=0;

        for (pair<int,int> v: a[root]){
            if (!del[v.first]){
                dfs(v.first,root,false,1,v.second);
                dfs(v.first,root,true,1,v.second);
            }
        }


        fill(dp+1, dp+deep+1, INF);

        for (pair<int,int> v: a[root]){
            if (!del[v.first]){
                solve(v.first);
            }
        }

        // return ans;
    }

} centroid;
void solve() {


    cin >> n >> k;

    for (int i=1; i<n; i++){
        int x,y, mm;
        cin >> x >> y >> mm;



        a[x].push_back({y,mm});
        a[y].push_back({x,mm});
    }



    // centroid.countChild(1,0);
    // cout << centroid.findCentroid(1,0,n) << "\n";


    centroid.init();
    centroid.solve(1);

    cout << ans << "\n";



}














