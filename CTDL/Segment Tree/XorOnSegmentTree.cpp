//******************/
//*   I<3   C++    */
//*  I WANT ANY AC */
//* I LOVE PROGRAM!*/
//*IT'S INTERESTING*/
//* I LOVE PROGRAM!*/
//*  IN CONTESTS   */
//*   GET SCORE    */
//*    AC CODE     */
//*     LET'S      */
//*      GO        */
//*  Written by:   */
//*   Duc Minh     */


// https://codeforces.com/contest/242/problem/E



#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define  file(name)  freopen(name".inp", "r", stdin);\
                     freopen(name".out", "w", stdout);
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define TIME        (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a)      a.begin(),a.end()
#define endl        "\n"
#define all1(a)     a+1,a+n+1
#define unordered_map  map
// #define push_back   emplace_back
// #define gcd(a,b)    __gcd(a,b);
// #define lcm(a,b)    (a*b)/gcd(a,b);

const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;
const long long MODD = 2024; /// 998244353
const long long maxN = 1e5+9;
const int LOG = sqrt(maxN);
const int mlift = 58;


template<class A> inline int __lg(A &a) {  return static_cast<int>(log2(a));}
template<class A,class B> inline void add(A &a,B b) { a+=b;while (a>=MOD) a-=MOD;}
template<class A,class B> inline void minus(A &a,B b) { a-=b;while (a>=MOD) a-=MOD;while (a<0) a+=MOD;}






///--------------------------------


void solve();

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif


    // file("BAI4");







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


long long a[maxN],n,q;


struct minh{

    long long tree[maxN*4], lz[maxN*4];



    void buildtree(int id, int l, int r, int a[]){
        if (l==r){
            tree[id]=a[l];
            // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
            return;
        }


        int m=(l+r) / 2;
        buildtree(id*2,l,m, a);
        buildtree(id*2+1,m+1,r, a);

        tree[id]=tree[id*2]+tree[id*2+1];
        // cout << id << ' ' << tree[id] << "\n";
    }


    void down(int id, int l, int r){


        if (!lz[id]) return;

        tree[id]=abs(tree[id]-(r-l+1)*lz[id]);
        if (l!=r) lz[id*2]=lz[id*2+1]^=lz[id];

        lz[id]=0;
    }

    void updatetree(int id, int l, int r, int u, int v, int val){
        down(id,l,r);
        if (u>r || v<l) return;

        if ((u <= l) && (r <= v)){
            lz[id]^=val;
            // tree[id]^=val;
            down(id,l,r);
            // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
            return;
        }


        int m=(l+r) / 2;
        updatetree(id*2, l , m, u ,v, val);
        updatetree(id*2+1,m+1,r,u,v,val);

        tree[id]=tree[id*2]+tree[id*2+1];
        // cout << id << ' ' << tree[id] << "\n";
    }


    long long gettree(int id, int l, int r, int u, int v){
        down(id,l,r);
        if (u>r || v<l) return -0;
        if ((u <= l) && (r <= v)) return tree[id];
        // if (l==r){
        //     return tree[id];
        // }

        int m=(l+r) / 2;
        return gettree(id*2, l, m, u, v) + gettree(id*2+1 ,m+1 ,r ,u, v);

    }
} seg[23];


int tam[maxN];


void solve(){

    // b[i][j] is jth bit in a[i]
    // 
    // query(l,r) = sum(j:0->19)  2^j * (sum(i:l->r) b[i][j])

    cin >> n;


    for (int i=1; i<=n; i++){
        cin >> a[i];
    }


    // buildtree
    



    // seg[1].buildtree(1,1,n);



    for (int j=0; j<=20; j++){
        for (int i=1; i<=n; i++){
            if ((a[i]>>j)&1) tam[i]=1;
            else tam[i]=0;
        }

        seg[j].buildtree(1,1,n,tam);
    }
    
    cin >> q;
    
    // cout << seg[0].gettree(1,1,n,2,4) << "\n";
    
    
    
    while (q--){
        int chos;
        cin >> chos;
    
        if (chos==1){
            int l, r;
            long long ans=0;
            cin >> l >> r;
    
                // cout << seg[1].gettree(1,1,n,l,r) << "\n";
                
    
            for (int j=20; j>=0; j--){
                ans+=1LL*(1LL<<j) * seg[j].gettree(1,1,n,l,r);
            }

            cout << ans << "\n";
        }
        else{
            int l,r,x;
            cin >> l >> r >> x;
    
            // seg[1].updatetree(1,1,n,l,r,x);
            

            for (int i=0; i<=20; i++){
                if ((x>>i)&1LL) seg[i].updatetree(1,1,n,l,r,1);
            }
        }
    }
    
}
    
    
    
    
    
    
    
    
    
    