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
const short LOG=18;


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






int n,q;
vector<int> a[200009];

int ans[200009], dep[200009], sz[200009];

// LCA

long long p[20][200005];

void dfs(int u){
    for (int i=0; i<a[u].size(); i++){

        int v=a[u][i];
        if (p[0][u] != v){
            p[0][v]=u;
            dep[v]=dep[u]+1;
            for (int i=1; i<=LOG; i++){
                p[i][v]= p[i-1][p[i-1][v]];
            }
            dfs(v);
            sz[u]+=sz[v];
        }
    }
}




int LCA(int u, int v){


    if (dep[u]<dep[v]) swap(u,v);

    int diff = dep[u]-dep[v];
    for (int i=0; i<=LOG; i++){
        if ((diff>>i) & 1){
            u=p[i][u];
        } 
    }
    // cout << u << ' ' << v << "\n";

    if (u==v) return u;




    for (int i=LOG; i>=0; i--){
        if (p[i][u]!=p[i][v]){
            u=p[i][u];
            v=p[i][v];
        }
    }




    return p[0][u];


}



// build HLD


int val[200009],ChainHead[200009], ChainID[200009], arr[200009], pos[200009], curpos=0,  curchain=0;
void HLD(int u, int par){
    if (!ChainHead[curchain]){
        ChainHead[curchain]=u;
    }

    ChainID[u]=curchain;
    pos[u]=curpos;
    arr[curpos]=u;
    curpos++;

    int nxt=0;
    for (int x: a[u]){
        if (x!=par){
            if (!nxt && sz[x]>sz[nxt]) nxt=x;
        }
    }

    if (nxt) HLD(nxt,u);

    for (int x: a[u]){
        if (x!=par && x!=nxt){
            curchain++;
            HLD(x,u);
        }
    }
}






// Segment Tree
long long tree[maxN*4],lz[maxN*4];
void down(int id, int l, int r){




    if (lz[id]) {

        tree[id]+=(r-l+1)*lz[id];
        if (l!=r) lz[id*2]=lz[id*2+1]+=lz[id];

        lz[id]=0;
    }


}



void buildtree(long long id, long long l, long long r){

    if (l==r){

        tree[id]=val[arr[l]];
        lz[id]=0;

        // cout << id << "\n";
        return;
    }

    long long m=(l+r)>>1;

    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id]=tree[id*2]^tree[id*2+1];

}


void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){


    // down(id,l,r);


    if (u>r || v<l) return;

    if (l==r){

        tree[id]=val;
        // lz[id]+=val;
        // down(id,l,r);


        return;

    }

    long long m=(l+r)>>1;

    updatetree(id*2,l,m,u,v,val);
    updatetree(id*2+1,m+1,r,u,v,val);

    tree[id]=tree[id*2]^tree[id*2+1];


}






long long gettree(long long id, long long l, long long r, long long u, long long v){

    // down(id,l,r);

    if (u>r || v<l) return 0;

    if (u<=l && r<=v) return tree[id];

    long long m=(l+r)>>1;

    return gettree(id*2,l,m,u,v)^gettree(id*2+1,m+1,r,u,v);
}


// Query
int query(int u, int v){


    int lca=LCA(u,v);
    int ans=0;

    // cout << u << ' ' << v << ' ' << lca << "\n";

    while (ChainID[u]!=ChainID[lca]){
        ans^=gettree(1,1,n,pos[ChainHead[ChainID[u]]],pos[u]);
        u = p[0][ChainHead[ChainID[u]]];
    }


    while (ChainID[v]!=ChainID[lca]){
        ans^=gettree(1,1,n,pos[ChainHead[ChainID[v]]],pos[v]);
        v = p[0][ChainHead[ChainID[v]]];
    }

    if (dep[u]<dep[v]) {
        ans^=gettree(1,1,n,pos[u],pos[v]);
    }
    else {
        ans^=gettree(1,1,n,pos[v],pos[u]);
    }

    return ans;
}
void solve() {



    
    cin >> n >> q;


    for (int i=1; i<=n; i++){
        cin >> val[i];
    }
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;


        a[x].push_back(y);
        a[y].push_back(x);
    }

    curpos = curchain = 1;
    dfs(1);
    HLD(1,1);

    buildtree(1,1,n);


    while (q--){
        char chos;
        cin >> chos;

        if (chos=='1'){
            int s,x;
            cin >> s >> x;

            // x -= val[s]; val[s] += x;

            updatetree(1,1,n,pos[s],pos[s],x);
            val[s]=x;
        }
        else {
            int l,r;
            cin >> l >> r;

            // cout << s << ' ' << st[s] << ' ' << en[s] << "\n";
            cout << query(l,r) << "\n";
        }
    }
}










