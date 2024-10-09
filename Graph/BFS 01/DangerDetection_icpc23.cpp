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

using namespace std;

#define TIME        (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a)      a.begin(),a.end()
#define endl        "\n"
#define all1(a)     a+1,a+n+1
// #define push_back   emplace_back
// #define gcd(a,b)    __gcd(a,b);
// #define lcm(a,b)    (a*b)/gcd(a,b);

const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;
// using mlong long = Modlong long<MOD>;
const long long MODD = 998244353;
const long long maxN = 2e6;






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

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};  // D R L U


int n,k;

int a[2009][2009],visited[2009][2009];

void solve1(){

    

    cin >> n >> k;


    for (int i=1; i<=n; i++){

        for (int j=1; j<=n; j++){

            cin >> a[i][j];

            if (a[i][j] < k) a[i][j]=1;
            else a[i][j]=0;

            visited[i][j]=false;
        }
    }



    deque<pair<pair<int,int>,int>> q;


    q.push_front({{1,1},0});

    while (q.empty()==false){

        int x=q.front().first.first, y=q.front().first.second, du=q.front().second;

        q.pop_front();


        if (visited[x][y]) continue;

        visited[x][y]=true;


        if (x==n && y==n){
            q.clear();

            return cout << du, void();
        }

        for (int i=0; i<4; i++){

            int xx=x+dx[i]; 
            int yy=y+dy[i];


            if (xx>0 && xx<=n && yy>0 && yy<=n){

                if (a[xx][yy]==1) q.push_back({{xx,yy},du+1});
                else q.push_front({{xx,yy},du});

                // visited[xx][yy]=true;
            }
        }
    }
}

bool check(int xxx){

    for (int i=1; i<=n; i++){

        for (int j=1; j<=n; j++){

            
            visited[i][j]=false;

            
        }
    }

    deque<pair<pair<int,int>,int>> q;


    q.push_front({{1,1},0});

    while (q.empty()==false){

        int x=q.front().first.first, y=q.front().first.second, du=q.front().second;

        q.pop_front();


        if (visited[x][y]) continue;

        visited[x][y]=true;

        // cout << x << ' ' << y << ' ' << du << "\n";


        if (x==n && y==n){

            
            q.clear();

            return du==0;
        }

        for (int i=0; i<4; i++){

            int xx=x+dx[i]; 
            int yy=y+dy[i];


            if (xx>0 && xx<=n && yy>0 && yy<=n){



                if (a[xx][yy]<xxx) q.push_back({{xx,yy},du+1});
                else q.push_front({{xx,yy},du});

                // visited[xx][yy]=true;
            }
        }
    }

    q.clear();

    return false;
}

void solve2(){

    

    cin >> n;


    int mx=-INF;
    for (int i=1; i<=n; i++){

        for (int j=1; j<=n; j++){

            cin >> a[i][j]; mx=max(mx,a[i][j]);
            visited[i][j]=false; 

            
        }
    }


    int l=1, r=10000, ans=1;


    while (l<=r){

        int mid=(l+r)/2;

        if (check(mid)) l=mid+1,ans=max(ans,mid);
        else r=mid-1;
    }

    cout << ans;
    
}


void solve(){

    
    

    int choose;

    cin >> choose;

    if (choose==1) solve1();
    else solve2();
    

    
 
}
