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
int INF = (int)1e9;
const int maxN = 200009;
// const long long du=1000000007;
// long long w[20],v[20];
// map<long long,long long> q;
// long long n,ans=INF;
// unsigned long long a[200009],pre[200009],x=0,sum=0;
// long long n,h[1000009],j[1000009],b[1000009];


long long tree[maxN*4],a[maxN];



void buildtree(int id, int l, int r){
    if (l==r){
        tree[id]=a[l];
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
        return;
    }


    int m=(l+r) / 2;
    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id]=max(tree[id*2],tree[id*2+1]);
    // cout << id << ' ' << tree[id] << "\n";
}

void updatetree(int id, int l, int r, int u, int v, int val){
    if (u>r || v<l) return;

    if (l==r){
        tree[id]+=val;
        return;
    }


    int m=(l+r) / 2;
    updatetree(id*2, l , m, u ,v, val);
    updatetree(id*2+1,m+1,r,u,v,val);

    tree[id]=max(tree[id*2],tree[id*2+1]);
}


int gettree(int id, int l, int r, int u, int v){
    if (u>r || v<l) return -INF;

    if (l==r){
        return tree[id];
    }

    int m=(l+r) / 2;
    return max(gettree(id*2, l, m, u, v), gettree(id*2+1 ,m+1 ,r ,u, v));

}
signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    
    int n,q;
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    buildtree(1,1,n);

    // for (int i=1; i<=n*4; i++){
    //     cout << tree[i] << ' ';
    // }

    while (q--){
        char ch;
        int l,r,x;
        cin >> ch;
        if (ch=='X'){
            cin >> l >> r >> x;
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






