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






using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e18;
const long long MOD=1e9+7;
const long long MODD=111539786; // 998244353
const int maxN=509;
const short LOG=18;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("moji");



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


int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

struct SegmentTree2D {
    int n, m;
    vector<vector<int>> seg;

    SegmentTree2D(int n, int m) : n(n), m(m), seg(4 * n, vector<int>(4 * m, 0)) {}

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry, const vector<vector<int>> &a) {
        if (ly == ry) {
            if (lx == rx) {
                seg[vx][vy] = a[lx][ly];
            } else {
                seg[vx][vy] = gcd(seg[vx * 2 + 1][vy], seg[vx * 2 + 2][vy]);
            }
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy * 2 + 1, ly, my, a);
            build_y(vx, lx, rx, vy * 2 + 2, my + 1, ry, a);
            seg[vx][vy] = gcd(seg[vx][vy * 2 + 1], seg[vx][vy * 2 + 2]);
        }
    }

    void build_x(int vx, int lx, int rx, const vector<vector<int>> &a) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx * 2 + 1, lx, mx, a);
            build_x(vx * 2 + 2, mx + 1, rx, a);
        }
        build_y(vx, lx, rx, 0, 0, m - 1, a);
    }

    void build(const vector<vector<int>> &a) {
        build_x(0, 0, n - 1, a);
    }

    int query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) return 0;
        if (ly == tly && ry == try_) return seg[vx][vy];
        int tmy = (tly + try_) / 2;
        return gcd(query_y(vx, vy * 2 + 1, tly, tmy, ly, min(ry, tmy)),
                   query_y(vx, vy * 2 + 2, tmy + 1, try_, max(ly, tmy + 1), ry));
    }

    int query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx) return 0;
        if (lx == tlx && rx == trx) return query_y(vx, 0, 0, m - 1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return gcd(query_x(vx * 2 + 1, tlx, tmx, lx, min(rx, tmx), ly, ry),
                   query_x(vx * 2 + 2, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }

    int query(int lx, int ly, int rx, int ry) {
        return query_x(0, 0, n - 1, lx, rx, ly, ry);
    }

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx) {
                seg[vx][vy] = new_val;
            } else {
                seg[vx][vy] = gcd(seg[vx * 2 + 1][vy], seg[vx * 2 + 2][vy]);
            }
        } else {
            int my = (ly + ry) / 2;
            if (y <= my) {
                update_y(vx, lx, rx, vy * 2 + 1, ly, my, y, new_val);
            } else {
                update_y(vx, lx, rx, vy * 2 + 2, my + 1, ry, y, new_val);
            }
            seg[vx][vy] = gcd(seg[vx][vy * 2 + 1], seg[vx][vy * 2 + 2]);
        }
    }

    void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) {
                update_x(vx * 2 + 1, lx, mx, x, y, new_val);
            } else {
                update_x(vx * 2 + 2, mx + 1, rx, x, y, new_val);
            }
        }
        update_y(vx, lx, rx, 0, 0, m - 1, y, new_val);
    }

    void update(int x, int y, int new_val) {
        update_x(0, 0, n - 1, x, y, new_val);
    }
};

void solve() {


    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    SegmentTree2D aa(n, m);
    aa.build(a);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1; --y1; --x2; --y2;
            cout << aa.query(x1, y1, x2, y2) << "\n";


        } else {
            int x, y, z;
            cin >> x >> y >> z;
            --x; --y;
            aa.update(x, y, z);
        }
    }


}













 