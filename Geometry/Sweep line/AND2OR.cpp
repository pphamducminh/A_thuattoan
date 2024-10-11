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


// a thai - VOI 24

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

#define int ll

int n,m,q;
int a[200009], b[200009];
bool mm[200009];
int pre[200009][LOG+2], pre1[200009][LOG+2];
vector<int> luu;


long long tree[maxN*4],lz[maxN*4];

void down(long long id, long long l, long long r) {
    int m=(l+r) / 2;
    long long t = lz[id];
    lz[id*2] += t;
    tree[id*2] += t*(m-l+1);

    lz[id*2+1] += t;
    tree[id*2+1] += t*(r-(m+1)+1);

    lz[id] = 0;
}

void buildtree(long long id, long long l, long long r){
    if (l==r){
        tree[id]=0;

        return;
    }


    long long m=(l+r) / 2;
    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id]=tree[id*2]+tree[id*2+1];

}

void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){
    
    if (u>r || v<l) return;


    if (u <= l && r <= v){
        tree[id]+=val*(r-l+1);
        lz[id]+=val;

        return;
    }

    long long m=(l+r) / 2;
    down(id,l,r);

    
    updatetree(id*2, l , m, u ,v, val);
    updatetree(id*2+1,m+1,r,u,v,val);

    tree[id]=tree[id*2]+tree[id*2+1];

}


long long gettree(long long id, long long l, long long r, long long u, long long v){
    if (u>r || v<l) return 0;
    if ((u <= l) && (r <= v)) return tree[id];


    long long m=(l+r) / 2;
    down(id,l,r);

    return gettree(id*2, l, m, u, v) + gettree(id*2+1 ,m+1 ,r ,u, v);

}

int ans[200009];
vector<pair<int,int>> qr[200009];
void solve(){
 
    cin >> n >> m >> q;    

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }


    for (int i=1; i<=m; i++){
        cin >> b[i];
    }


    for (int i=1; i<=n; i++){
        for (int j=0; j<=LOG; j++){
            pre1[i][j]=pre1[i-1][j];
        }

        for (int j=0; j<=LOG; j++){
            if (!((a[i]>>j)&1)) pre1[i][j]=i;
        }
    }

    for (int i=1; i<=m; i++){
        for (int j=0; j<=LOG; j++){
            pre[i][j]=pre[i-1][j];
        }

        for (int j=0; j<=LOG; j++){
            if ((b[i]>>j)&1) pre[i][j]=i;
        }
    }
    // cout << pre[2][0] << "\n";



    // cout << (2000|100013) << "\n";

    for (int i=1; i<=m; i++){
        long long tam=b[i];

        luu.clear();
        for (int j=0; j<=LOG; j++){
            if (!((tam>>j)&1)) {
                if (pre[i-1][j]) luu.push_back(pre[i-1][j]);
            }
        }

        sort(all(luu),greater<int>());
        luu.resize(unique(luu.begin(), luu.end()) - luu.begin());

        mm[tam]=1;
        for (int x: luu) {
            tam|=b[x];
            mm[tam]=1;
        }
        // cout << "\n";
    }

    // for (int i=0; i<=1e5; i++){
        // cout << i << ' ' << mm[i] << "\n";
    // }


    // cout << (8&6&2) << "\n";

    if (q==1) {
        int l,h;
        cin >> l >> h;

        long long ans=0;
        for (int i=l; i<=h; i++){
            luu.clear();

            int tam=a[i];
            for (int j=0; j<=LOG; j++){
                if ((a[i]>>j)&1) 
                    if (pre1[i-1][j] && pre1[i-1][j]>=l) luu.push_back(pre1[i-1][j]);
            }

            sort(all(luu),greater<int>());
            luu.resize(unique(luu.begin(), luu.end()) - luu.begin());

            int ok=0, lst=i;
            if (mm[tam]) ok=1;

            // cout << i << ' ' << tam << "\n";
            for (int x: luu) {
                if (ok) ans+=(lst-(x+1)+1);
                tam&=a[x];
                lst=x;
                // cout << x << "\n";
                if (mm[tam]) ok=1;
                else ok=0;
            }
            if (ok) ans+=(lst-l+1);
            // cout << i << ' ' << ans << "\n";
        }

        cout << ans << "\n";

        return void();
    }


    for (int i=1; i<=q; i++) {
        int l,h;
        cin >> l >> h;


        qr[h].push_back({l,i});
    }

    for (int i=1; i<=n; i++){
        luu.clear();

        int tam=a[i];
        for (int j=0; j<=LOG; j++){
            if ((a[i]>>j)&1) 
                if (pre1[i-1][j]) luu.push_back(pre1[i-1][j]);
        }

        sort(all(luu),greater<int>());
        luu.resize(unique(luu.begin(), luu.end()) - luu.begin());

        int ok=0, lst=i;
        if (mm[tam]) ok=1;

        // cout << i << ' ' << tam << "\n";
        for (int x: luu) {
            if (ok) {
                // ans+=(lst-(x+1)+1);
                updatetree(1,1,n,x+1,lst,1);
            }
            tam&=a[x];
            lst=x;
            // cout << x << "\n";
            if (mm[tam]) ok=1;
            else ok=0;
        }
        if (ok) {
            // ans+=(lst-l+1);
            updatetree(1,1,n,1,lst,1);
        }




        for (pair<int,int> x: qr[i]){
            ans[x.second]=gettree(1,1,n,x.first,i);
            // cout << i << ' ' << x.second << ' ' << ans[x.second] << "\n";
        }
    }

    for (int i=1; i<=q; i++){
        cout << ans[i] << "\n";
    }
}
 
 
 







