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


class SegmentTree2D {
public:
    int n, m;
    vector<vector<int>> tree;

    SegmentTree2D(vector<vector<int>> a) {
        n = a.size();
        m = a[0].size();
        tree.resize(2 * n, vector<int>(2 * m, 0));
        build(a);


    }

    void build(vector<vector<int>> a) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tree[i + n][j + m] = a[i][j];
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j > 0; j--) {
                tree[i + n][j] = gcd(tree[i + n][j * 2], tree[i + n][j * 2 + 1]);
            }
        }


        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < 2 * m; j++) {
                tree[i][j] = gcd(tree[i * 2][j], tree[i * 2 + 1][j]);
            }
        }
    }

    int query(int x1, int y1, int x2, int y2) {
        int res = 0;
        x1 += n;
        x2 += n;
        y1 += m;
        y2 += m;

        while (x1 <= x2) {
            if (x1 % 2 == 1) {
                res = gcd(res, queryRow(x1, y1, y2));
                x1++;
            }
            if (x2 % 2 == 0) {
                res = gcd(res, queryRow(x2, y1, y2));
                x2--;
            }
            x1 /= 2;
            x2 /= 2;
        }
        return res;
    }

    int queryRow(int row, int y1, int y2) {
        int res = 0;
        while (y1 <= y2) {
            if (y1 % 2 == 1) {
                res = gcd(res, tree[row][y1]);
                y1++;
            }
            if (y2 % 2 == 0) {
                res = gcd(res, tree[row][y2]);
                y2--;
            }
            y1 /= 2;
            y2 /= 2;
        }
        return res;
    }

    void update(int x, int y, int value) {
        x += n;
        y += m;
        tree[x][y] = value;


        for (int j = y; j > 1; j /= 2) {
            tree[x][j / 2] = gcd(tree[x][j], tree[x][j ^ 1]);
        }


        for (int i = x; i > 1; i /= 2) {
            for (int j = 0; j < 2 * m; j++) {
                tree[i / 2][j] = gcd(tree[i][j], tree[i ^ 1][j]);
            }
        }
    }

private:
    int gcd(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};


void solve() {


    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n, vector<int>(m));


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    SegmentTree2D aa(a);

    for (int i=0; i<q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << aa.query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << "\n";


        } else if (op == 2) {


            int x, y, z;
            cin >> x >> y >> z;
            aa.update(x - 1, y - 1, z);
        }
    }


}













 