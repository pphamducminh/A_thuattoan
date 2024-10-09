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
const long long MODD = 998244353; /// 998244353
const long long maxN = 5e5+9;

template<class A> inline int __lg(A &a) {  return static_cast<int>(std::log2(a));}
template<class A,class B> inline void add(A &a,B b) { a+=b;while (a>=MOD) a-=MOD;}
template<class A,class B> inline void minus(A &a,B b) { a-=b;while (a>=MOD) a-=MOD;while (a<0) a+=MOD;}





///--------------------------------


void solve();

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("tbrackets");







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

int a[maxN];
long long bit[maxN];


void update(int p, int val){

    for (int i=p; i<=n; i+= i&-i){
        bit[i]+=val;
    }
}

long long get(int p){

    long long ans=0;
    for (int i=p; i; i-= i&-i){
        ans+=bit[i];
    }
    return ans;
}

void solve(){






    cin >> n >> q;
    for (int i=1; i<=n; i++){
        int x;
        cin >> a[i];
        update(i,a[i]);
    }

    // buildtree(1,1,n);

    // for (int i=1; i<=n*4; i++){
    //     cout << tree[i] << ' ';
    // }

    while (q--){
        char ch;
        int l,r,x;
        cin >> ch;
        if (ch=='1'){
            cin >> l >> x; 

            // buildtree(1,1,n);
            update(l,x-a[l]); a[l]=x;

        }
        else{


            cin >> l >> r;

            cout << get(r) - get(l-1) << "\n";
        }
    }


}







