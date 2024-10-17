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


// https://lqdoj.edu.vn/problem/cses1190

struct cay{
    long long pre,suf,sum,maxsum;
    static cay inf() { return { -INF, -INF, 0, -INF }; }
};
long long a[maxN],lz[maxN*4],maxtam=-INF;
cay tree[maxN*4];

// void down(long long id, long long l, long long r) {
//     long long m=(l+r) / 2;
//     long long t = lz[id];
//     lz[id*2] += t;
//     tree[id*2] += t*(m-l+1);

//     lz[id*2+1] += t;
//     tree[id*2+1] += t*(r-(m+1)+1);

//     lz[id] = 0;
// }

void buildtree(long long id, long long l, long long r){
    if (l==r){
        tree[id].pre=a[l];
        tree[id].suf=a[l];
        tree[id].sum=a[l];
        tree[id].maxsum=a[l];
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
        return;
    }


    long long m=(l+r) / 2;
    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].pre=max(tree[id*2].pre,tree[id*2].sum+tree[id*2+1].pre);
    tree[id].suf=max(tree[id*2+1].suf,tree[id*2+1].sum+tree[id*2].suf);

    tree[id].maxsum=max(tree[id*2].maxsum,tree[id*2+1].maxsum);
    tree[id].maxsum=max(tree[id].maxsum, tree[id*2].suf + tree[id*2+1].pre);


    // cout << id << ' ' << tree[id] << "\n";
}

void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){
    
    if (u>r || v<l) return;

    if (l==r){
        tree[id].pre=val;
        tree[id].suf=val;
        tree[id].sum=val;
        tree[id].maxsum=val;
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
        return;
    }


    // if (u <= l && r <= v){
    //     tree[id]+=val;
    //     // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
    //     return;
    // }

    long long m=(l+r) / 2;

    
    updatetree(id*2, l , m, u ,v, val);
    updatetree(id*2+1,m+1,r,u,v,val);

    tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    tree[id].pre=max(tree[id*2].pre,tree[id*2].sum+tree[id*2+1].pre);
    tree[id].suf=max(tree[id*2+1].suf,tree[id*2+1].sum+tree[id*2].suf);

    tree[id].maxsum=max(tree[id*2].maxsum,tree[id*2+1].maxsum);
    tree[id].maxsum=max(tree[id].maxsum, tree[id*2].suf + tree[id*2+1].pre);
    // cout << id << ' ' << tree[id] << "\n";
}


cay gettree(long long id, long long l, long long r, long long u, long long v){
    if (u>r || v<l) return cay::inf();
    if ((u <= l) && (r <= v)) return tree[id];
    // if (l==r){
    //     return tree[id];
    // }

    long long m=(l+r) / 2;
    // return max(gettree(id*2, l, m, u, v).maxsum, gettree(id*2+1 ,m+1 ,r ,u, v).maxsum);

    cay tam1=gettree(id*2, l, m, u, v), tam2=gettree(id*2+1 ,m+1 ,r ,u, v);
    cay res;
        res.pre = max(tam1.pre, tam2.pre + tam1.sum);
        res.suf = max(tam2.suf, tam1.suf + tam2.sum);
        res.sum = tam1.sum + tam2.sum;
        res.maxsum = max(tam1.maxsum, tam2.maxsum);
        res.maxsum = max(res.maxsum, tam1.suf + tam2.pre);
    return res;

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
    //     cout << tree[i].maxsum << ' ';
    // }
    
    
    

    while (q--){
        char ch;
        long long l,r,x,ans=-INF;
        // cin >> ch;
        // if (ch=='0'){
        //     cin >> l  >> x; 

        //     // buildtree(1,1,n);
        //     updatetree(1,1,n,l,l,x);
        // }
        // else{
        //     cin >> l >> r >> x;
        //     cout << gettree(1,1,n,l,r,x) << "\n";
        // }
        




        cin >> l >> x;

        


        updatetree(1,1,n,l,l,x);

        cout << max(gettree(1,1,n,1,n).maxsum,0LL) << "\n";
        
    }

    cerr << "Time elapsed: " << TIME << "s.\n";
    cerr << "ducminh" << "\n";
    return 0;
}






