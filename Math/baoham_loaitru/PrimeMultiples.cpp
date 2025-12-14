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

const long long INF = (long long)1LL<<60;
const long long MOD = (long long)1e9+7;
const long long MODD = 14062008; /// 998244353
const long long maxN = 25009;






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




void solve(){

    long long n,k,ans=0,a[200009];
    cin >> n >> k;

    for (long long i=1; i<=k; i++){
        cin >> a[i];

        ans+=n/a[i];
    }




    for (long long mask=1; mask<(1<<k); mask++){

        if (__builtin_popcount(mask)<2) continue;


        long long mul=1;
        for (long long i=1; i<=k; i++){

            if ((mask>>(i-1))&1) {

                if (mul>=n/a[i]+1) {mul=INF; break;}
                mul*=a[i];
            }
        } 

        // cout << mask << ' ' << mul << "\n";

        long long tam=n/mul;

        // cout << tam << "\n";


        if (__builtin_popcount(mask)&1) ans+=tam;
        else ans-=tam;


    }

    cout << ans << "\n";

}
