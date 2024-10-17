#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
long long INF = (long long)1e18;
const long long maxN = 200009;
// const long long du=1000000007;
// long long w[20],v[20];
// map<long long,long long> q;
// long long n,ans=INF;
// unsigned long long a[200009],pre[200009],x=0,sum=0;
// long long n,h[1000009],j[1000009],b[1000009];


long long tree[maxN*4],a[maxN],lz[maxN*4];

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
        tree[id]=a[l];
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
        return;
    }


    long long m=(l+r) / 2;
    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id]=tree[id*2]+tree[id*2+1];
    // cout << id << ' ' << tree[id] << "\n";
}

void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){
    
    if (u>r || v<l) return;

    // if (l==r){
    //     tree[id]+=val;
    //     lz[id]+=val;
    //     // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
    //     return;
    // }


    if (u <= l && r <= v){
        tree[id]+=val*(r-l+1);
        lz[id]+=val;
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
        return;
    }

    long long m=(l+r) / 2;
    down(id,l,r);

    
    updatetree(id*2, l , m, u ,v, val);
    updatetree(id*2+1,m+1,r,u,v,val);

    tree[id]=tree[id*2]+tree[id*2+1];
    // cout << id << ' ' << tree[id] << "\n";
}


long long gettree(long long id, long long l, long long r, long long u, long long v){
    if (u>r || v<l) return 0;
    if ((u <= l) && (r <= v)) return tree[id];
    // if (l==r){
    //     return tree[id];
    // }

    long long m=(l+r) / 2;
    down(id,l,r);

    return gettree(id*2, l, m, u, v) + gettree(id*2+1 ,m+1 ,r ,u, v);

}
signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    
    long long n,q;
    cin >> n >> q;
    for (long long i=1; i<=n; i++){
        cin >> a[i];
    }
    buildtree(1,1,n);

    

    // for (long long i=1; i<=n*4; i++){
    //     cout << tree[i] << ' ';
    // }

    while (q--){
        char ch;
        long long l,r,x;
        cin >> ch;
        if (ch=='1'){
            cin >> l >> r >> x; 

            // buildtree(1,1,n);
            updatetree(1,1,n,l,r,x);
        }
        else{
            cin >> l >> r;
            cout << gettree(1,1,n,l,r) << "\n";
        }
    }

    cerr << "Time elapsed: " << TIME << "s.\n";
    cerr << "ducminh" << "\n";
    return 0;
}






