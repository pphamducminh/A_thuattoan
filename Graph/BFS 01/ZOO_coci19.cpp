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
 
 
// bfs 01
// 
// https://oj.uz/problem/view/COCI19_zoo
 
 
 
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
 
const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;
const long long MODD = 1e9; /// 998244353
const long long maxN = 2e5+9;
 
 
 
 
 
 
///--------------------------------
 
 
void solve();
 
signed main(){
 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif


    // file("dance");
 
 
 
 
 
 
 
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
 


char a[2009][2009];
int dp[2009][2009],ans=-INF;
int n,m;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

long long truoc[200009],luu[200009],fi[200009],las[200009],dep[200009],d=0;

bool valid(int x, int y){
    if (x<1 || y<1 || x>n || y>m || a[x][y]=='*') return false;
    return true;
}


void solve(){
    

    cin >> n >> m;

    memset(dp, 0x3f, sizeof dp);
    dp[1][1]=1;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }



    deque<pair<int,int>> q;

    q.push_front({1,1});

    while (q.empty()==false){
        int x=q.front().first, y=q.front().second; // du=q.front().second;
        q.pop_front();


        for (int k=0; k<4; k++){
            int xx=x+dx[k];
            int yy=y+dy[k];

            if (!valid(xx,yy)) continue;

            int cost=(a[xx][yy]!=a[x][y]?1:0);
            if (dp[xx][yy]>dp[x][y]+cost){
                dp[xx][yy]=dp[x][y]+cost;

                if (cost) q.push_back({xx,yy});
                else q.push_front({xx,yy});
            } 
        }
    }


    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (!valid(i,j)) continue;
            ans=max(ans,dp[i][j]);
        }
    }

    cout << ans;
}











