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
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC optimize("Ofast","inline","no-stack-protector")
// #pragma GCC target("arch=skylake")

using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD[] = {(long long)1e9+22071997,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=1e6+9;
const long long LOG=19;
const double eps = 1e-6;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("drawatree");



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

int n,m,p;
vector<pair<int,long long>> a[200009];
int degree[200009],cnt[200009],inqueue[200009], truoc[200009], st=0;
long long luu[200009];


bool spfa(int x){
    for (int i=0; i<=n; i++){
        cnt[i]=0;
        luu[i]=INF;
        inqueue[i]=false;
        truoc[i]=-1;
    }
    queue<int> q;

    luu[x]=0;
    inqueue[x]=true;
    q.push(x);

    while (!q.empty()){
        int u=q.front(); q.pop();

        inqueue[u]=false;
        
        for (pair<int,int> tam: a[u]){
            int v=tam.first, w=tam.second;

            if (luu[u]+w<luu[v]){
                luu[v]=luu[u]+w;
                truoc[v]=u;
                if (!inqueue[v]){
                    q.push(v);
                    inqueue[v]=true;
                    cnt[v]++;
                    if (cnt[v]>n) {
                        st=v;
                        return false; // chu trinh am
                    }
                }      
            }
        }       
    }
    return true;
}
void solve(){

    cin >> n >> m;


    for (int i=1; i<=m; i++){
        int u,v,mm;
        cin >> u >> v >> mm;

        a[u].push_back({v,mm});
    }


    // if (checkct()) return cout << -1 << "\n", void();
    
    for (int i=1; i<=n; i++){
        if (!spfa(i)){
            cout << "YES\n";
            for (int j=1; j<=n; j++) st=truoc[st];
            vector<int> ans;

            int st1=st;
            ans.push_back(st);
            while (truoc[st]!=st1){
                st=truoc[st];
                ans.push_back(st);
            }
            ans.push_back(st1);
            reverse(all(ans));
            
            for (int x: ans) cout << x << ' ';
            return void();
        }
    }
    cout << "NO\n";
}






