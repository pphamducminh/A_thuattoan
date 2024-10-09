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

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9+7;
const long long MODD = 1LL * MOD * MOD; /// 998244353
const long long maxN = 3e5+9;
const int LOG = 131;
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



long long pbase[maxN], hashpre[maxN], hashp=0, hashsuf[maxN];


long long get(long long i,long long j) {
    return (hashsuf[i]+ MODD - hashsuf[j+1] * pbase[j - i + 1] ) % MOD;
}



bool check(const string s) {
    long long n = s.length();
    for (long long i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}


void solve(){


    string s,ans1="", ans2="";

    cin >> s;

    string s1 = string(s.rbegin(), s.rend());
    string p = s + s1;    

    if (check(s)) return cout << s, void();

    long long lens=s.length();


    s=' '+s;
    s1=' '+s1;


    pbase[0]=1;
    for (long long i=1; i<=lens; i++){
        pbase[i]=(pbase[i-1]*LOG)%MOD;
    }


    hashpre[0]=0;
    for (long long i=1; i<=lens; i++){
        hashpre[i]=(hashpre[i-1]*LOG+s[i])%MOD;
    }
    hashsuf[lens+1]=0;
    for (long long i=lens; i>=1; i--){
        hashsuf[i]=(hashsuf[i+1]*LOG+s[i])%MOD;
    }



    for (long long i = lens; i >= 1; --i) {
        if (hashpre[i] == get(1,i)) {
            string en=s.substr(i+1,lens-i);
            reverse(all(en));
            // cout << i << ' ' << s[i] << ' ' << s1[s.length()-i] << "\n";
            
            // cout << en << ' ' << s.substr(1,lens) << "\n";
            ans1 = en + s.substr(1,lens);
            break;
        }
    }


    hashpre[0]=0;
    for (long long i=1; i<=lens; i++){
        hashpre[i]=(hashpre[i-1]*LOG+s1[i])%MOD;
    }
    hashsuf[lens+1]=0;
    for (long long i=lens; i>=1; i--){
        hashsuf[i]=(hashsuf[i+1]*LOG+s1[i])%MOD;
    }



    for (long long i = lens; i >= 1; --i) {
        if (hashpre[i] == get(1,i)) {
            string en=s1.substr(i+1,lens-i);
            reverse(all(en));
            // cout << i << ' ' << s[i] << ' ' << s1[s.length()-i] << "\n";
            
            // cout << en << ' ' << s1.substr(1,lens) << "\n";
            ans2 = en + s1.substr(1,lens);
            break;
        }
    }
    if (ans1.length()<ans2.length()) cout << ans1;
    else cout << ans2;



    
}
    
    
    
    
    
    
    
    
    
