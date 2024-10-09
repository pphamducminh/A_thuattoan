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
// #define long long long long
// #define push_back   emplace_back
// #define gcd(a,b)    __gcd(a,b);
// #define lcm(a,b)    (a*b)/gcd(a,b);

const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;
const long long MODD = 998244353;
const long long maxN = 18;






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



long long n,k,a[209],b[209],lo=0,vmax=INF,cost[maxN][maxN],best=INF,luucost=0,m;




long long masks[maxN][1 << (maxN + 1)];


long long TSP(long long i, long long mask){

    // Kết quả của bài toán con này là chúng ta phải di chuyển tất cả các nút j trong mặt nạ và kết thúc đường dẫn tại nút thứ i, vì vậy, với mỗi nút j trong mặt nạ, tính toán đệ quy chi phí di chuyển tất cả các nút trong mặt nạ ngoại trừ i và sau đó di chuyển trở lại từ nút j đến nút tôi đi đường đi ngắn nhất lấy tối thiểu tất cả j nút có thể
    
    if (mask == ((1 << i) | 3))
        return cost[1][i];
    
    if (masks[i][mask] != 0)
        return masks[i][mask];
 
    long long res = INF; 
 
    
 
    for (long long j = 1; j <= n; j++)
        if ((mask>>j)&1 && j != i && j != 1)
            res = min(res, TSP(j, mask & (~(1 << i)))+ cost[j][i]); // mask & (~(1 << i))) is S-{i}
    return masks[i][mask] = res;
}


void solve(){

    


    


    cin >> n >> m;



    for (long long i=1; i<=n; i++)
        for (long long j=1; j<=n; j++)
            cost[i][j]=INF;

    
    for (long long i=1; i<=m; i++){
        long long x,y,mm;

        cin >> x >> y >> mm;

        cost[x][y]=mm;
        cost[y][x]=mm;  
    }
    for (long long i=1; i<=n; i++)
            cost[i][i]=0;
        

    

    // p[1]=true; b[1]=1; 
  
    // TSP(1);

    

    for (long long i = 1; i <= n; i++)
        
        best = min(best, TSP(i, (1 << (n + 1)) - 1)+ cost[i][1]);

    cout << ((best==INF)?-1:best) << "\n";

    

    
}
