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
const int maxN=2e5+9;
const short LOG=18;


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
vector<int> a[200009], a_bcc[200009];
pair<int,int> dscanh[200009];
stack<int> st;
int low[200009], num[200009], in_bcc[200009], dbcc=0, ti=0;
bool used[200009];
vector<int> luu[200009];



void tarjan(int u) {
    low[u] = num[u] = ++num[0];
    for (int x: a[u]) {
        int v=x;
        if(!num[v]) {
            st.push(u);
            tarjan(v);
            low[u] = min(low[u], low[v]);

            if(low[v] >= num[u]) {

                dbcc++;
                a_bcc[u].push_back(n + dbcc);
                luu[dbcc].push_back(u);
                do {
                    v = st.top();
                    st.pop();
                    if(u != v && in_bcc[v] != dbcc) {
                        luu[dbcc].push_back(v);
                        a_bcc[n + dbcc].push_back(v);
                        in_bcc[v] = dbcc;
                    }
                } while(v != u);
            }
        } else {
            low[u] = min(low[u], num[v]);
        }
    }

    st.push(u);
}


void solve(){




    cin >> n >> m;

    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;

        dscanh[i]={u,v};
        a[u].push_back(v);
        a[v].push_back(u);
    }


    for (int i=1; i<=n; i++){
        if (!num[i]) tarjan(i);
    }

    cout << dbcc << "\n";

    for (int i=1; i<=dbcc; i++){
        cout << luu[i].size() << ' ';
        for (int x: luu[i]) {
            cout << x << ' ';
        }
        cout << "\n";
    }





}
 
 
 







