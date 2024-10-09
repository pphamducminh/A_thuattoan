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

const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;
const long long MODD = 1e9; /// 998244353
const long long maxN = 3e5+9;
const int LOG = 21;
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


    // file("flower");







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


long long n,m,s,f,ok=0,k,st=0,en=0;
// vector<long long> a[200009];
int a[2009][2009];
bool visited[2009][2009];
long long luu[2009][2009],exi[200009],truoc[200009],luu1[2009][2009],luu2[2009][2009],tt[2009][2009];
vector<long long> ver,exi1;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

void bfs(int u, int v){

    deque<pair<int,int>> q;
    q.push_front({u,v});

    // visited[u][v]=true;

    while (q.empty()==false){

        int x=q.front().first, y=q.front().second; q.pop_front();

        if (visited[x][y]) continue;
        visited[x][y]=true;

        
        // cout << x << ' ' << y << ' ' << luu[x][y] << "\n";

        for (int k=0; k<4; k++){

            int xx=x+dx[k];
            int yy=y+dy[k];

            if (xx<1 || xx>n || yy<1 || yy>m) continue;

            // cout << x << ' ' << y << ' ' << xx << ' ' << yy << ' ' << tt[xx][yy] << "\n";

            if (a[xx][yy]==1){

                tt[xx][yy]++;
                if (tt[xx][yy]>=2){
                    q.push_back({xx,yy});
                    luu[xx][yy]=min(luu[xx][yy],luu[x][y]+1);
                    // visited[xx][yy]=true;
                    
                }
            }
            else{
                q.push_front({xx,yy});
                luu[xx][yy]=luu[x][y];
            }

            // cout << xx << ' ' << yy << ' ' << tt[xx][yy] << ' ' << luu[xx][yy] << "\n";
            

    
        }
    }
}





void solve(){


    int posl=0, posr=0;
    pair<int,int> luumx;

    cin >> n >> m;


    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            luu[i][j]=INF;
        }
    }




    for (int i=1; i<=n; i++){
        a[i][1]=a[i][m]=0;
        luu[i][1]=luu[i][m]=0;
 

    }
 
    for (int i=1; i<=m; i++){
        a[1][i]=a[n][i]=0;
        luu[1][i]=luu[n][i]=0;
 

    }



    bfs(1,1);



    long long mx=-INF;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // if (a[i][j]!='0') cout << luu[i][j] << ' ';
            // else cout << '*' << ' ';
            if (a[i][j]!='0') mx=max(mx,luu[i][j]);
        }
        // cout << "\n";
    }

    cout << mx;




}




