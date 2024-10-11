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




// https://oj.vnoi.info/problem/area


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
// #define push_back emplace_back
#define endl "\n"
#define all1(a) a+1,a+n+1

// #define gcd(a,b) __gcd(a,b);
// #define lcm(a,b) (a*b)/gcd(a,b);
const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;

const long long MODD = 998244353;
const long long maxN = 2e6;
// const unsigned unsigned long long du=1000000007;
// unsigned unsigned long long w[20],v[20];
// map<unsigned unsigned long long,unsigned unsigned long long> q;
// unsigned unsigned long long n,ans=INF;
// unsigned unsigned unsigned long long a[200009],pre[200009],x=0,sum=0;
// unsigned unsigned long long n,h[1000009],j[1000009],b[1000009];


// unsigned unsigned long long t,n,x,a[1000009];


// unsigned long long t,a[10000009],max1i[10000009],maxin[10000009],maxx=-INF;




///--------------------------------


void solve();

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif


    // freopen("spath.inp", "r", stdin); 
    // freopen("spath.out", "w", stdout);
    
    
    
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

struct minh{

    int x,y1,y2,t;
};

bool cmp(minh &a, minh &b){
    return a.x<b.x;
}
vector<minh> a;
pair<int,int> tree[200009];




void updatetree(int id, int l, int r, int u, int v, int val){
    if (u>r || v<l) return;

    // if (l==r){
    if ((u <= l) && (r <= v)){
        tree[id].second+=val;

        if (tree[id].second!=0) tree[id].first=r-l+1;
        else {
            if (l==r) tree[id].first=0; else tree[id].first=tree[id*2].first + tree[id*2+1].first;
        }
        // cout << id << ' ' << tree[id] << ' ' << l << ' ' << r <<  "\n";
        return;
    }


    int m=(l+r) / 2;
    updatetree(id*2, l , m, u ,v, val);
    updatetree(id*2+1,m+1,r,u,v,val);

    if (tree[id].second!=0) tree[id].first=r-l+1;
    else tree[id].first=tree[id*2].first+tree[id*2+1].first;
    // cout << id << ' ' << tree[id] << "\n";
}

void solve(){


    
    long long n;

    cin >> n;

    for (int i=1; i<=n; i++){

        int x1,x2,y1,y2;

        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1,y1,y2,1});
        a.push_back({x2,y1,y2,-1});
    }
    

    sort(all(a),cmp);

    int ans=0;
    for (int i=0; i<a.size()-1; i++){

        updatetree(1,0,30000,a[i].y1, a[i].y2-1, a[i].t);
        ans+=(a[i+1].x - a[i].x) * tree[1].first;

        // cout << i << ' ' << tree[1].first << ' ' << a[i].x << ' ' << a[i+1].x << "\n";
    }

    cout << ans << "\n";
}
