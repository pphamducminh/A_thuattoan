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

const long long INF=1e17;
const long long MOD=1e9+7;
const long long MODD=998244353; // 998244353
const int maxN=2e5+9;
const long long LOG=18;
const double eps = 1e-6;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("MAZETRAP");



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


int n,q;
long long a[200009];
struct sqrtDecomposition{
    long long block[200009];
    int blocksz=447;

    void init(int n){   
        blocksz=sqrt(n);

        for (int i=1; i<=n; i++){
            block[i/blocksz]+=a[i];
        }
    }

    void update(int p, int val){
        block[p/blocksz]+=(val-a[p]);
        a[p]=val;
    }

    long long get(int l, int r){
        long long ans=0;
        int blockl=(l+blocksz-1)/blocksz;
        int blockr=r/blocksz-1;

        if (blockl>blockr){
            for (int i=l; i<=r; i++){
                ans+=a[i];
            }
            return ans;
        }

        for (int i=blockl; i<=blockr; i++){
            ans+=block[i];
        }
        for (int i=l; i<=blockl*blocksz-1; i++){
            ans+=a[i];
        }
        for (int i=(blockr+1)*blocksz; i<=r; i++){
            ans+=a[i];
        }
        return ans;
    }


} sq;
void solve(){
 
 
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sq.init(n);

    while (q--){
        int op;
        cin >> op;

        if (op==1){
            int k,x;
            cin >> k >> x;

            sq.update(k,x);
        }
        else {
            int l,r;
            cin >> l >> r;

            cout << sq.get(l,r) << "\n";
        }
    }

 
 
}
 
 



 