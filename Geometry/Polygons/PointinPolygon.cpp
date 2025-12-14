#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("Ofast","inline","no-stack-protector")
// #pragma GCC target("arch=skylake")
 
using namespace std;
 
 
#define file(name) freopen(name".inp","r",stdin); \
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long
#define ull unsigned long long
 
 
 
 
const long long INF=(1e9);
const long long MOD=1e9+7;
const long long MODD[] = {(long long)998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=5e5+2;
const long long LOG=18;
const double eps = 1e-7;
 
 
//------------------------
 
 
 
void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     file("ducminh");
    // #endif
 
 
 
 
    int t;
 
    // cin >> t;
 
    t=1;
 
 
    while (t--){
        solve();
    }
    return 0;
}
 
/// -------------- PROBLEM SOLUION --------------------
#define P complex<ll>
 
#define X real()
 
#define Y imag()
 
int n,m;
 
ll cross(P a, P b, P c) {
    P u = b - a;
    P v = c - a;
    ll cp = (conj(u)*v).Y;
    return (cp > 0) - (cp < 0);
}
 
bool comp(const P &a, const P &b) {
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}
 
bool mid(P a, P b, P c) {
 
    vector<P> v = {a, b, c};
    sort(v.begin(), v.end(), comp);
    return (v[1] == c);
}
 
bool check(P a, P b, P c, P d) {
    ll cp1 = cross(a, b, c);
    ll cp2 = cross(a, b, d);
    ll cp3 = cross(c, d, a);
    ll cp4 = cross(c, d, b);
    if (cp1 * cp2 < 0 && cp3 * cp4 < 0) return 1;
    if (cp3 == 0 && mid(c, d, a) && cp4 < 0) return 1;
    if (cp4 == 0 && mid(c, d, b) && cp3 < 0) return 1;
    return 0;
}
 
void solve() {
    cin >> n >> m;
    vector<P> polygon;
    vector<pair<ll, ll>> points(m);
    for (ll i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        polygon.push_back({x, y});
    }
 
    polygon.push_back(polygon[0]);
 
    for (int i=0; i<m; i++){
        cin >> points[i].first >> points[i].second;
    }
    for (ll i = 0; i < m; i++) {
        P point = {points[i].first, points[i].second};
        P infinity = {INF, INF};
        ll cnt = 0;
        ll flag = 0;
        for (ll j = 0; j < n; j++) {
            ll cp = cross(polygon[j], polygon[j+1], point);
            if (cp == 0 && mid(polygon[j], polygon[j+1], point)) {
                flag = 1;
                break;
            }
            cnt += check(polygon[j], polygon[j+1], point, infinity);
        }
        if (flag) cout << "BOUNDARY" << endl;
        else cout << (cnt & 1 ? "INSIDE" : "OUTSIDE") << endl;
    }
 
}