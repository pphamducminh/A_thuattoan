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


int n;
int a[1009][1009];


struct Hungarian_algo {

    long long c[1009][1009];
    vector<long long> u,v,match;
    int n,m;

    void init(int _n, int _m){
        n=_n; m=_m;

        u.assign(n+1,0); v.assign(m+1,0); match.assign(m+1,0);
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                c[i][j]=INF;
            }
        }

    }

    void addedge(int u, int v, long long w){
        c[u][v]=w;
    }

    pair<long long, vector<pair<long long, long long>>> calc(){

        for (int i=1; i<=n; i++){
            vector<bool> visited(m+1,false);
            vector<long long> luu(m+1,INF), truoc(m+1,-1);


            // nut 0 gia 
            match[0]=i;
            int j0=0;

            // use dijkstra
            do {
                visited[j0]=true;

                int i0=match[j0];
                int j1;
                long long delta=INF;

                for (int j=1; j<=m; j++){
                    if (!visited[j]){
                        long long cp=c[i0][j]-u[i0]-v[j];

                        if (cp<luu[j]){
                            luu[j]=cp;
                            truoc[j]=j0;
                        }

                        if (luu[j]<delta){
                            delta=luu[j];
                            j1=j;
                        }
                    }
                }

                for (int j=0; j<=m; j++){
                    if (visited[j]){
                        u[match[j]]+=delta; v[j]-=delta;
                    }
                    else luu[j]-=delta;
                }

                j0=j1;
            } while (match[j0]);



            // update alternating path
            while (j0){
                int j1=truoc[j0];
                match[j0]=match[j1];
                j0=j1;
            }
        }

        vector<pair<long long, long long>> ans;

        for (int i=1; i<=n; i++){
            if (match[i]){
                ans.push_back({match[i],i});
            }
        }

        return {-v[0],ans};
    }
};

Hungarian_algo aa;
void solve(){

    cin >> n;

    aa.init(n,n);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
            aa.addedge(i,j,a[i][j]);
        }
    }



    auto ans=aa.calc();

    cout << ans.first << "\n";


    for (pair<int,int> x: ans.second) {
        cout << x.first << ' ' << x.second << "\n";
    }


}
