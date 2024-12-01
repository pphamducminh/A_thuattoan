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
void solve(){

    double x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    Point A(x1,y1);
    Point B(x2,y2);
    Point C(x3,y3);


    Point AB=B-A;

    // cout << AB;
    
    // Shoelace or Gauss
    cout << setprecision(6) << fixed << abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;

}





