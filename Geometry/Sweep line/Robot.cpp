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


// https://oj.vnoi.info/problem/icpc23_mb_b

using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
// #define push_back emplace_back
#define endl "\n"
#define all1(a) a+1,a+n+1
#define uniqueV(x)   sort(all(x)), (x).resize(unique(all(x)) - x.begin())

// #define gcd(a,b) __gcd(a,b);
// #define lcm(a,b) (a*b)/gcd(a,b);
const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;

const long long MODD = 998244353;
const long long maxN = 1e6;
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

    long long x,y1,y2,t;
};
struct Range {
    long long l, r, d;
 
    Range(long long _l = 0, long long _r = 0, long long _d = 0) : l(_l), r(_r), d(_d) { }
};

bool cmp(minh &a, minh &b){
    return a.x<b.x;
}
vector<pair<pair<long long,long long>, pair<long long,long long>>> a;
pair<long long,long long> tree[maxN];
long long X[maxN], Y[maxN], U[maxN], V[maxN];
vector<Range> quer[maxN];
vector<long long> vx, vy;


void Build(long long v, long long tl, long long tr) {
    if (tl == tr) return;
 
    long long mid = (tl + tr) >> 1;
 
    Build(v << 1, tl, mid);
    Build(v << 1 | 1, mid + 1, tr);
 
    tree[v] = {0, 0};
}
void updatetree(long long v, long long tl, long long tr, long long l, long long r, long long x) {
    if (l <= tl && tr <= r) {
        tree[v].first += x;
 
        if (tree[v].first > 0) tree[v].second = vy[tr] - vy[tl - 1];
        else tree[v].second = tree[v << 1].second + tree[v << 1 | 1].second;
 
        return;
    }
 
    long long mid = (tl + tr) >> 1;
 
    if (r <= mid) updatetree(v << 1, tl, mid, l, r, x);
    else if (l > mid) updatetree(v << 1 | 1, mid + 1, tr, l, r, x);
    else {
        updatetree(v << 1, tl, mid, l, mid, x);
        updatetree(v << 1 | 1, mid + 1, tr, mid + 1, r, x);
    }
 
    if (tree[v].first <= 0)
        tree[v].second = tree[v << 1].second + tree[v << 1 | 1].second;    
}
 


void nen(vector<pair<pair<long long,long long>, pair<long long,long long>>> rect) {
    long long n = rect.size();
 
    for (long long i = 0; i < n; i++) {
        X[i] = rect[i].first.first, Y[i] = rect[i].first.second;
        U[i] = rect[i].second.first, V[i] = rect[i].second.second;
 
        vx.push_back(X[i]); vy.push_back(Y[i]);
        vx.push_back(U[i]); vy.push_back(V[i]);
    }
 
    uniqueV(vx);
    uniqueV(vy);
 
    for (long long i = 0; i < n; i++) {
        X[i] = lower_bound(all(vx), X[i]) - vx.begin();
        Y[i] = lower_bound(all(vy), Y[i]) - vy.begin();
 
        U[i] = lower_bound(all(vx), U[i]) - vx.begin();
        V[i] = lower_bound(all(vy), V[i]) - vy.begin();
 
        if (X[i] < U[i] && Y[i] < V[i]) {
            quer[X[i] + 1].push_back(Range(Y[i] + 1, V[i], 1));
 
            quer[U[i] + 1].push_back(Range(Y[i] + 1, V[i], -1));
        }
    }
}
void solve(){


    
    long long n,k,X=0,Y=0;

    cin >> k >> n;

    pair<long long, long long> pos = {0, 0};
    for (long long i=1; i<=n; i++){

        char c; long long D;
        cin >> c >> D;
 
        pair<long long, long long> npos = pos;
        if (c == 'E') npos.first += D;
        if (c == 'W') npos.first -= D;
        if (c == 'N') npos.second += D;
        if (c == 'S') npos.second -= D;
 
        a.push_back({{min(pos.first, npos.first), min(pos.second, npos.second)}
                , {max(pos.first, npos.first) + k, max(pos.second, npos.second) + k}});
 
        pos = npos;
    }
    

    // sort(all(a),cmp);

    nen(a);
    Build(1, 1, 2 * n);

    long long ans = 0; 
    for (long long i = 1; i < vx.size(); i++) {
        for (Range x : quer[i]) {
            long long l = x.l, r = x.r, d = x.d;
 
            updatetree(1, 1, 2 * n, l, r, d);
        }
 
        ans += (vx[i] - vx[i - 1]) * tree[1].second;
    }
 

    cout << ans << "\n";
}
