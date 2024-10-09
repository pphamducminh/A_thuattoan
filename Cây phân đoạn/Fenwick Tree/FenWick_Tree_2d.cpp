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
const long long maxN = 2e3+9;

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



long long pre[2000009];
long long pre1[2009][2009];
int n,m;
int a[maxN][maxN];
long long bit[maxN][maxN];




long long convert1d(int i, int j){

    return (i-1)*m+j;
}



void update(int p1, int p2,  int val){

    for (int i=p1; i<=n; i+= i&-i){
        for (int j=p2; j<=m; j+= j&-j){

            bit[i][j]+=val;
        }
    }
}

long long get(int p1, int p2){

    long long ans=0;
    for (int i=p1; i; i-= i&-i){
        for (int j=p2; j; j-= j&-j){

            ans+=bit[i][j];
        }
    }
    return ans;
}


long long pref2d(int u, int v, int x ,int y){

    return get(x,y)-get(x,v-1)-get(u-1,y)+get(u-1,v-1);
}





void solve(){





    cin >> n >> m;

    for (int i=1; i<=n; i++){

        for (int j=1; j<=m; j++){
            cin >> a[i][j];

            // int id=convert1d(i,j);

            // a1[id]=a[i][j];

            // pre1[i][j]=pre1[i-1][j]+pre1[i][j-1]-pre1[i-1][j-1]+a[i][j];
            
            update(i,j,a[i][j]);
        }
    }

    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=m; j++){
    //         int id=convert1d(i,j);

    //         pre[id]=pre1[i][j];


    //     }
    // }


    // cout << a1[15] << "\n";

    // buildtree(1,1,n*m);

    // cout << gettree(1,1,n*m,1,5) << "\n";

    int q;

    cin >> q;

    while (q--){

        char chos;

        cin >> chos;

        if (chos=='1'){

            int x,y,v;
            cin >> x >> y >> v;
            // int id=convert1d(x,y);




            update(x,y,v);
        }
        else{

            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;

            // int id1=convert1d(x1,y1);
            // int id2=convert1d(x2,y2);

            // int xx1=x1-1, yy1=m;
            // int xx2=x1-1, yy2=m;



            // cout << id1 << ' ' << id2 << "\n";

            cout << pref2d(x1,y1,x2,y2) << "\n";


        }
    }


}







