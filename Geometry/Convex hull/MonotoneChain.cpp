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
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("Ofast","inline","no-stack-protector")
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
const long long MODD[] = {998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=1e6+9;
const long long LOG=256;
const double eps = 1e-6;
 
 
//------------------------
 
 
 
void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif
 
    // file("CARNAVAL");
 
 
 
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
 
    
#define double long double
 
struct Point{
    typedef ll T;
    T x,y;
    // init
    Point(T _x=0, T _y=0) : x(_x), y(_y) {}
 
 
    // so sanh
    bool operator < (Point p) const { return tie(x,y)<tie(p.x,p.y); } 
    bool operator > (Point p) const { return tie(x,y)>tie(p.x,p.y); } 
    bool operator == (Point p) const { return tie(x,y)==tie(p.x,p.y); } 
    bool operator != (Point p) const { return tie(x,y)!=tie(p.x,p.y); } 
 
    Point operator + (Point p) const { return Point(x+p.x, y+p.y); } // cong 2 diem
    Point operator - (Point p) const { return Point(x-p.x, y-p.y); } // tru 2 diem
    T operator * (Point p) const { return x*p.x + y*p.y; } // tich vo huong
    T operator ^ (Point p) const { return x*p.y - y*p.x; } // tich co huong
 
    // nhan hang so d
    Point operator * (T d) const { return Point(x*d, y*d); }
    Point operator / (T d) const { return Point(x/d, y/d); }
 
    T len2() const { return x*x + y*y; } // binh phuong do dai vector
    double len() const { return sqrt((double)(len2())); } // do dai vector
    Point vg() const { return Point(-y,x); } // vector vuong goc
 
    friend ostream& operator << (ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")"; 
    }
};
 
 
long long ccw(const Point &P0, const Point &P1, const Point &P2) {
    return (P1-P0) ^ (P2-P1);
}
long long sign(const ll &x){
    return (x>=0?(x?1:0):-1);
}
 
 
 
// Monotone chain
vector<Point> a;
bool cmp(Point u, Point v){
    return u.x<v.x || (u.x==v.x && u.y<v.y);
}
vector<Point> convexHull(vector<Point> &v){
 
 
    int n=v.size();
    if (n<=2) return v;
    sort(all(v), cmp);
 
    int m=0;
    vector<Point> hull(n*2);
    hull[m++]=v[0];
    for (int i=1; i<n; i++){
        while (m>=2 && sign(ccw(hull[m-2],hull[m-1],v[i]))<0) m--;
        hull[m++]=v[i];
    }
    for (int i=n-2; i>=0; i--){
        while (m>=2 && sign(ccw(hull[m-2],hull[m-1],v[i]))<0) m--;
        hull[m++]=v[i];
    }
    if (n>1) m--;
    
 
    return {hull.begin(), hull.begin()+m};
}
 
vector<Point> ans;
void solve(){
 
 
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
 
        a.push_back(Point(x,y));
    }
 
 
    ans=convexHull(a);
 
    cout << ans.size() << "\n";
    for (Point v: ans){
        cout << v.x << ' ' << v.y << "\n";
    }
    
 
    // cout << setprecision(10) << fixed << ans;
 
 
 
 
}