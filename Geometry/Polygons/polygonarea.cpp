#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
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
#include <random>
#include <sstream>
 
 
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC optimize("Ofast","inline","no-stack-protector")
// #pragma GCC target("arch=skylake")
 
using namespace std;
 
 
#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long
 
 
 
const long long INF=1e18;
const long long MOD=1e9+7;
const long long MODD[] = {(long long)998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=2e5+9;
const long long LOG=18;
const double eps = 1e-5;
 
 
//------------------------
 
 
 
void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif
 
    // file("PNUM");
 
 
 
    int t;
 
    // cin >> t;
 
    t=1;
 
    while (t--){
        solve();
    }
 
    cerr << "Time: " << TIME << "s.\n";
    cerr << "ducminh";
    return 0;
}
 
/// -------------- PROBLEM SOLUION --------------------
 
struct Point{
    typedef ll T;
    T x,y;
    Point(T _x=0, T _y=0) : x(_x), y(_y) {}
 
    // so sanh
    bool operator < (Point p) const { return tie(x,y)<tie(p.x,p.y); }
    bool operator > (Point p) const { return tie(x,y)>tie(p.x,p.y); }
    bool operator == (Point p) const { return tie(x,y)==tie(p.x,p.y); }
    bool operator != (Point p) const { return tie(x,y)!=tie(p.x,p.y); }
 
    Point operator + (Point p) const { return Point(x+p.x,y+p.y); } // cong 2 vector
    Point operator - (Point p) const { return Point(x-p.x,y-p.y); } // tru 2 vector
    T operator * (Point p) const { return x*p.x+y*p.y; } // tvh
    T operator ^ (Point p) const { return x*p.y-y*p.x; } // tch
 
    // nhan hang so
    Point operator * (T d) const { return Point(x*d,y*d); }
    Point operator / (T d) const { return Point(x/d,y/d); }
 
    T len2() const { return x*x+y*y; }
    double len() const { return sqrt((double)len2()); }
    Point vg() const { return Point(-y,x); }
 
    friend ostream& operator << (ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};
 
long long ccw(const Point &P0, const Point &P1, const Point &P2){
    return (P1-P0)^(P2-P1);
}
int sign(const ll &x){
    if (x<0) return -1;
    if (x==0) return 0;
    return 1;
}
 
Point a[200009];
void solve(){
 
    double xa,ya,xb,yb,xc,yc;
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++){
        cin >> a[i].x >> a[i].y;
    }
 
    long long ans=0;
    for (int i=0; i<n; i++){
        int j=(i+1)%n;
 
        ans+=(a[i]^a[j]);
    }
 
 
    cout << setprecision(0) << fixed << abs(ans);
 
 
}
