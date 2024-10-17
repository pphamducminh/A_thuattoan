//******************/
//*   I<3   C++    */
//*  I WANT ANY AC */
//* I LOVE PROGRAM!*/
//*IT'S long longERESTING*/
//* I LOVE PROGRAM!*/
//*  IN CONTESTS   */
//*   GET SCORE    */
//*    AC CODE     */
//*     LET'S      */
//*      GO        */
//*  Written by:   */
//*   Duc Minh     */




// https://cses.fi/problemset/result/7407986/


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
#include <cctype>
#include <cstring>
#include <iomanip>
#include <deque>

using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
// #define push_back emplace_back
#define endl "\n"
#define all1(a) a+1,a+n+1

// #define gcd(a,b) __gcd(a,b);
// #define lcm(a,b) (a*b)/gcd(a,b);
const long long INF = (long long)1e18;
const long long MOD = (long long)1e9+7;

const long long MODD = 998244353;
const long long maxN = 2e6;
// const unsigned unsigned long long du=1000000007;
// unsigned unsigned long long w[20],v[20];
// map<unsigned unsigned long long,unsigned unsigned long long> q;
// unsigned unsigned long long n,ans=INF;
// unsigned unsigned unsigned long long a[200009],pre[200009],x=0,sum=0;
// unsigned unsigned long long n,h[1000009],j[1000009],b[1000009];


// unsigned unsigned long long t,n,x,a[1000009];


// unsigned long long t,a[10000009],max1i[10000009],maxin[10000009],maxx=-INF;




///--------------------------------


void solve();

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif


    
    

    
    long long t;


    // cin >> t;
    
    t=1;



    while (t--){
       



        solve();
       

    }

    

    

    cerr << "Time elapsed: " << TIME << "s.\n";
    cerr << "ducminh" << "\n";
    return 0;
}



///--------------------[PROBLEM SOLUTION]--------------------///

long long tree[maxN*4], a[maxN], lazy[maxN*4];


void buildtree(long long id, long long l, long long r){

    if (l==r){
        tree[id]=a[l];

        return;
    }

    long long m=(l+r)/2;

    buildtree(id*2,l,m);
    buildtree(id*2+1,m+1,r);

    tree[id]=max(tree[id*2],tree[id*2+1]);
}


void down(long long id, long long l, long long r){
    // if (!lazy[id]) return;

    long long m=(l+r)/2;
    long long tam=lazy[id];
    

    // tree[id]+=tam;

    tree[id*2]+=tam;
    lazy[id*2]+=tam;

    tree[id*2+1]+=tam;
    lazy[id*2+1]+=tam;

    lazy[id]=0;
    
}

void updatetree(long long id, long long l, long long r, long long u, long long v, long long val){

    down(id,l,r);

    if (l>v || u>r) return;

    if (u <= l && r <= v){

        tree[id]+=val;
        lazy[id]+=val;

        return;

    }

    long long m=(l+r)/2;

    updatetree(id*2,l,m,u,v,val);
    updatetree(id*2+1,m+1,r,u,v,val);


    tree[id]=max(tree[id*2],tree[id*2+1]);
}

long long gettree(long long id, long long l, long long r, long long u, long long v){

    down(id,l,r);
    


    if (l>v || u>r) return -INF;

    if (u <= l && r <= v){

        return tree[id];

    }

    long long m=(l+r)/2;


    

    return max(gettree(id*2,l,m,u,v),gettree(id*2+1,m+1,r,u,v));
}


void solve(){
 
 
    long long n,q;

    cin >> n >> q; 



    for (long long i=1; i<=n; i++){

        cin >> a[i];
    }

    buildtree(1,1,n);


    while (q--){

        long long ch;

        cin >> ch;

        if (ch==1){

            long long l,r,x;

            cin >> l >> r >> x;

            updatetree(1,1,n,l,r,x);

        }
        else{

            long long x;

            cin >> x;


            cout << gettree(1,1,n,x,x) << "\n"; 


        }
    }
 
}












