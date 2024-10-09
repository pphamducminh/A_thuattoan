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


long long pbase[maxN],pre[maxN], suf[maxN], sz;

long long getl(int i, int j){

    return (pre[j]-pre[i-1] * pbase[j-i+1] + MOD*MOD) %MOD;
}

long long getr(int i, int j){

    return (suf[sz-i+1]-suf[sz-j] * pbase[j-i+1] + MOD*MOD) %MOD;
}

string sol(string s){

    s=' '+s;

    string ans="";

    pre[0]=0;
    for (int i=1; i<=sz; i++){
        pre[i]=(pre[i-1]*LOG+s[i]-'a'+1)%MOD;
        suf[i]=(suf[i-1]*LOG+s[sz-i+1]-'a'+1)%MOD;
    }



    for (int i=sz; i>=1; i--){
        if (getl(1,i) == getr(1,i)){
            string en=s.substr(i+1,sz);

            reverse(all(en));

            ans=en + s.substr(1,sz);
            break;
        }
    }

    return ans;
}

void solve(){


    string s;
    cin >> s;


    sz=s.length();

    pbase[0]=1;

    for (int i=1; i<=sz; i++){
        pbase[i]=(pbase[i-1]*LOG)%MOD;
    }

    string ans1=sol(s);

    reverse(all(s));

    string ans2=sol(s);

    if (ans1.length() < ans2.length()) cout << ans1;
    else cout << ans2;

}
    
    
    
    
    
    
    
    
    
