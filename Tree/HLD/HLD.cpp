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

const long long INF=1e17;
const long long MOD=1e9+7;
const long long MODD=998244353; // 998244353
const int maxN=2e5+9;
const long long LOG=18;
const double eps = 1e-6;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("MAZETRAP");



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

int n,q;
vector<int> a[maxN];
int val[maxN];


// segmenttree
int tree[maxN*4], lz[maxN*4];
void down(int id, int l, int r){
    if (!lz[id]) return;
    int tam=lz[id];

    tree[id]=tam;
    if (l!=r){
        lz[id<<1]+=tam;
        lz[id<<1|1]+=tam;
    }

    lz[id]=0;
}
void buildtree(int id, int l, int r){
    if (l>r) return;
    if (l==r){
        tree[id]=val[l];
        return;
    }

    int mid=(l+r)>>1;
    buildtree(id<<1,l,mid);
    buildtree(id<<1|1,mid+1,r);
    tree[id]=max(tree[id<<1],tree[id<<1|1]);
}

void updatetree(int id, int l, int r, int u, int v, int val){
    down(id,l,r);
    if (l>v || r<u) return;

    if (u<=l && r<=v) {
        lz[id]+=val;
        down(id,l,r);

        return;
    }

    int mid=(l+r)>>1;
    updatetree(id<<1,l,mid,u,v,val);
    updatetree(id<<1|1,mid+1,r,u,v,val);

    tree[id]=max(tree[id<<1],tree[id<<1|1]);
}

int gettree(int id, int l, int r, int u, int v){
    down(id,l,r);
    if (l>v || r<u) return 0;

    if (u<=l && r<=v) return tree[id];

    int mid=(l+r)>>1;
    return max(gettree(id<<1,l,mid,u,v) , gettree(id<<1|1,mid+1,r,u,v));
}




struct HeavyLightDecomposition {
    int cnts=0,cntp=1;
    int chainhead[maxN], idst[maxN], idpath[maxN], p[maxN], dep[maxN], in[maxN], out[maxN];

    HeavyLightDecomposition(){
        chainhead[1]=1;
    }


    void dfs(int u, int par){
        idst[u]=++cnts;
        idpath[u]=cntp;
        p[u]=par;
        dep[u]=dep[par]+1;
        in[u]=cnts;

        bool ok=1;
        for (int x: a[u]){
            if (x==par) continue;

            if (!ok){
                cntp++;
                chainhead[x]=x;
            }
            else {
                ok=0;
                chainhead[x]=chainhead[u];
            }
            dfs(x,u);
        }

        out[u]=cnts;
    }

    void updatepath(int u, int v, int val){
        while (chainhead[u]!=chainhead[v]){
            if (dep[p[chainhead[u]]]<dep[p[chainhead[v]]]) swap(u,v);

            updatetree(1,1,n,idst[chainhead[u]], idst[u], val);
            u=p[chainhead[u]];
        }

        if (idst[u]>idst[v]) swap(u,v);
        updatetree(1,1,n,idst[u],idst[v], val);
    }
    int getpath(int u, int v){
        int ans=0;
        while (chainhead[u]!=chainhead[v]){
            if (dep[p[chainhead[u]]]<dep[p[chainhead[v]]]) swap(u,v);

            ans=max(ans,gettree(1,1,n,idst[chainhead[u]],idst[u]));
            u=p[chainhead[u]];
        }

        if (idst[u]>idst[v]) swap(u,v);
        ans=max(ans,gettree(1,1,n,idst[u],idst[v]));

        return ans;
    }

    void updateroot(int u, int val){
        updatetree(1,1,n,in[u],out[u],val);
    }
    int getroot(int u){
        return gettree(1,1,n,in[u],out[u]);
    }


} hld;

void solve(){


    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    hld.dfs(1,0);
    for (int i=1; i<=n; i++){
        updatetree(1,1,n,hld.in[i],hld.in[i],val[i]);
    }


    while (q--){
        int op;
        cin >> op;

        if (op==1){
            int s,x;
            cin >> s >> x;

            updatetree(1,1,n,hld.in[s],hld.in[s],x);
        }
        else {
            int u,v;
            cin >> u >> v;
            cout << hld.getpath(u,v) << " ";
        }
    }


}















