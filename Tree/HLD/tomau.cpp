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
const long long MODD=998244353; // 998244353
const int maxN=2e5+9;
const short LOG=20;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("COLTR");



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



vector<int> a[200009];
int par[200009], dep[200009], rnk[200009], sta[200009], en[200009], head[200009], curr_pos = 0;
int c[200009];
int n, q;


long long tree[maxN*4],lz[maxN*4];



void down(long long id, long long l, long long r) {

    if (l==r) return;


    int m=(l+r)>>1;
    long long t = lz[id];
    if (t) {
        lz[id<<1] = t;
        tree[id<<1] = t;

        lz[id<<1|1] = t;
        tree[id<<1|1] = t;
    }

    lz[id] = 0;
}



void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){
    
    if (u>r || v<l) return;

    down(id,l,r);

    if (u <= l && r <= v){
        tree[id]=(1LL<<val);
        lz[id]=(1LL<<val);

        return;
    }

    long long m=(l+r) / 2;
    

    
    updatetree(id<<1, l , m, u ,v, val);
    updatetree(id<<1|1,m+1,r,u,v,val);

    tree[id]=tree[id<<1]|tree[id<<1|1];

}


long long gettree(long long id, long long l, long long r, long long u, long long v){
    if (u>r || v<l) return 0;
    down(id,l,r);
    if ((u <= l) && (r <= v)) return tree[id];

    long long m=(l+r) / 2;
    

    return gettree(id<<1, l, m, u, v) | gettree(id<<1|1 ,m+1 ,r ,u, v);

}



void dfs(int u) {
    rnk[u] = 1;
    for (int &v : a[u]) {
        if (v != par[u]) {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
            rnk[u] += rnk[v];
            if (rnk[v] > rnk[a[u][0]]) swap(a[u][0], v);
        }
    }
}

void hld(int u, int h) {
    head[u] = h;
    sta[u] = ++curr_pos;
    updatetree(1,1,n, sta[u], sta[u], c[u]);
    for (int v : a[u]) {
        if (v != par[u]) {
            hld(v, (v == a[u][0]) ? h : v);
        }
    }
    en[u] = curr_pos;
}

void upd1(int u, int v, int new_c) {
    while (head[u] != head[v]) {
        if (dep[head[u]] > dep[head[v]]) {
            updatetree(1,1,n, sta[head[u]], sta[u], new_c);
            u = par[head[u]];
        } else {
            updatetree(1,1,n, sta[head[v]], sta[v], new_c);
            v = par[head[v]];
        }
    }
    if (dep[u] > dep[v]) swap(u, v);
    updatetree(1,1,n, sta[u], sta[v], new_c);
}



void upd2(int u, int new_c) {
    updatetree(1,1,n, sta[u], en[u], new_c);
}



int qr1(int u, int v) {
    int ans=0;
    while (head[u] != head[v]) {
        if (dep[head[u]] > dep[head[v]]) {
            ans|=gettree(1,1,n, sta[head[u]], sta[u]);
            u = par[head[u]];
        } else {
            ans|=gettree(1,1,n, sta[head[v]], sta[v]);
            v = par[head[v]];
        }
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans|=gettree(1,1,n, sta[u], sta[v]);
    return __builtin_popcountll(ans);
}

int qr2(int u) {
    int ans = gettree(1,1,n, sta[u], en[u]);
    return __builtin_popcountll(ans);
}


void init(){
    for (int i=1; i<=n; i++){
        updatetree(1,1,n,sta[i],sta[i],c[i]);
    }
}

void solve(){

    cin >> n >> q;
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }




    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }

    dep[1] = 0;
    dfs(1);
    hld(1, 1);

    init();

    // cout << sta[5] << "\n";

    // st.updatetree(0,0,200000-1,5,5,60);
    // cout << par[9] << "\n";

    while (q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int u, v, x;
            cin >> u >> v >> x;
            upd1(u, v, x);
        } else if (k == 2) {
            int u, x;
            cin >> u >> x;
            upd2(u, x);
        } else if (k == 3) {
            int u, v;
            cin >> u >> v;
            cout << qr1(u, v) << "\n";
        } else if (k == 4) {
            int u;
            cin >> u;
            cout << qr2(u) << "\n";
        }
    }



}
