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

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define push_back emplace_back
#define all1(a) a+1,a+n+1
// #define gcd(a,b) __gcd(a,b);
// #define lcm(a,b) (a*b)/gcd(a,b);
long long INF = (long long)1e9;
long long MOD = (long long)1e9+7;

long long MODD = 998244353;
const long long maxN = 509;
// const unsigned unsigned long long du=1000000007;
// unsigned unsigned long long w[20],v[20];
// map<unsigned unsigned long long,unsigned unsigned long long> q;
// unsigned unsigned long long n,ans=INF;
// unsigned unsigned unsigned long long a[200009],pre[200009],x=0,sum=0;
// unsigned unsigned long long n,h[1000009],j[1000009],b[1000009];


// unsigned unsigned long long t,n,x,a[1000009];


// unsigned long long t,a[10000009],max1i[10000009],maxin[10000009],maxx=-INF;

// vector<vector<string>> a(200009);  // khong trong so



int n,m,a[1009][2009],pre[1009][1009];

deque<int> dq1;
deque<int> dq;
int ll[1009];



void solve(){



    
    

    

    int ans=-INF;

    cin >> n >> m;

    for (int i=1; i<=n; i++){


        for (int j=1; j<=m; j++){

            cin >> a[i][j];
            pre[i][j]=(a[i][j]==1);
        }
    }

    for (int i=2; i<=n; i++){


        for (int j=1; j<=m; j++){

            pre[i][j]+=pre[i-1][j];

            if (!a[i][j]) pre[i][j]=0;
        }
    }

    
    for (int i=1; i<=n; i++){

        while (dq1.size()) dq1.pop_front();
        dq1.push_back(1);

        fill(ll,ll+m+1,0);

        // cout << dq1.back() << "\n";

        for (int j=2; j<=m; j++){


            // cout << pre[i][j] << ' ';

            while (dq1.size() && pre[i][dq1.back()]>=pre[i][j] && dq1.back()!=1) dq1.pop_back();
            

            ll[j]=dq1.back();

            

            // if (i==9) cout << j << ' ' << dq1.back() << ' ' << pre[i][dq1.back()] << '\n';

            while (dq1.size() && (pre[i][dq1.front()]>=pre[i][j])) dq1.pop_front();
            
            dq1.push_back(j);
            
        }

        
        

        while (dq.size()) dq.pop_front();
        dq.push_back(m);
        // ans=max(ans,pre[i][m]*(m-ll[m]-1));
        for (int j=m-1; j>=1; j--){

            // cout << pre[i][j] << ' ';

            while (dq.size() && pre[i][dq.front()]>=pre[i][j] && dq.front()!=m) dq.pop_front();
            

            int l=j-1, r=dq.front();

            // while (pre[i][l]>=pre[i][j]) l--;
            // while (pre[i][r]>=pre[i][j]) r++;
            

            // if (pre[i][j]*(r-ll[j]-1)>ans){

            //     cout << i << ' ' << j << ' ' << r << ' ' << ll[j] << ' ' << pre[i][j] << "\n";
            // }

            if (r==m && pre[i][r]>=pre[i][j]) r=m+1;

            if (l==1 && pre[i][l]>=pre[i][j]) l=m-1;

            ans=max(ans,pre[i][j]*(r-ll[j]-1));

            

            // if (i==9) cout << j << ' ' << dq.front() << ' ' << pre[i][dq.front()] << '\n';

            while (dq.size() && (pre[i][dq.back()]>=pre[i][j])) dq.pop_back();
            
            dq.push_front(j);
            
        }
        

        // cout << "\n";
    }


    cout << ans;




    

}




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
