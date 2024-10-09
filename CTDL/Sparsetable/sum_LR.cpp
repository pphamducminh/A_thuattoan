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

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9+7;
const long long MODD = 1e9; /// 998244353
const long long maxN = 2e5+9;
const int LOG = 25;
const int mlift = 18;


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


    // file("");







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


int n,q;


int a[maxN], st[LOG + 1][maxN];
void build() {
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LOG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = (st[j - 1][i] + st[j - 1][i + (1 << (j - 1))]);
}


int log2_floor(int n){
    return n ? __builtin_clzll(1) - __builtin_clzll(n) : -1;
}
long long query(int l, int r) {

    long long ans=0;
    for (int i=LOG; i>=0; i--){

        if ((1<<i) <= (r-l+1)){

            ans+=st[i][l];

            l+=(1<<i);
        }
    }

    return ans;
}




long long binpow(long long a, long long b){
 
    long long ans=1;
 
    while (b){
        if (b&1) ans=(ans*a)%MOD;
 
        a=(a*a)%MOD;
        b>>=1;
    }
 
    return ans;
}


void solve(){


    cin >> n >> q;
    

    for (int i=1; i<=n; i++){

        cin >> a[i];
    }

    build();

    while (q--){

        int l,r;
        cin >> l >> r;



        // int tam=

        cout << query(l,r) << "\n";
    }
}














