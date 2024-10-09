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


long long n, k;
long long ans=0, sum[maxN];
vector<int> a[maxN];



struct CentroidDecomposition {

    int maxh,del[maxN],child[maxN], deep=0, dp[maxN];


    void init(){
        fill(dp,dp+n+1,0);
        fill(del,del+n+1,0);
        fill(child,child+n+1,0);

        dp[0]=1;
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

        if (d>k) return;
        deep=max(deep,d);

        if (type) dp[d]++;
        else ans+=dp[k-d];



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

        // dfs(root,n);

        del[root]=1;

        deep=0;

        for (int v: a[root]){
            if (!del[v]){
                dfs(v,root,false);
                dfs(v,root,true);
            }
        }

        fill(dp+1, dp+deep+1, 0);

        for (int v: a[root]){
            if (!del[v]){
                solve(v);
            }
        }

        // return ans;
    }

} centroid;
void solve() {


    cin >> n >> k;

    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;



        a[x].push_back(y);
        a[y].push_back(x);
    }



    // centroid.countChild(1,0);
    // cout << centroid.findCentroid(1,0,n) << "\n";

    centroid.init();
    centroid.solve(1);

    cout << ans << "\n";



}














