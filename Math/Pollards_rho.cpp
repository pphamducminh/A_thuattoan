#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
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


using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1

const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD=998244353;
const int maxN=2e5+9;
const int LOG=31;

//------------------------


void solve();

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("knight");

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


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


long long binpow(long long a, long long b, long long mod) {
    long long ans = 0;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return ans;
}


long long pollards_rho(long long n) {
    if (n % 2 == 0) return 2;
    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long c = rand() % (n - 1) + 1;
    long long d = 1;

    while (d == 1) {
        x = (binpow(x, x, n) + c + n) % n;
        y = (binpow(y, y, n) + c + n) % n;
        y = (binpow(y, y, n) + c + n) % n;
        d = gcd(abs(x - y), n);
        if (d == n) return pollards_rho(n);
    }

    return d;
}


void sang(long long n, vector<long long>& luu) {
    if (n == 1) return;
    if (n % 2 == 0) {
        luu.push_back(2);
        while (n % 2 == 0) n /= 2;
    }

    if (n == 1) return;

    if (n < 10000000000) { 
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                luu.push_back(i);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) luu.push_back(n);
        return;
    }

    long long factor = pollards_rho(n);
    sang(factor, luu);
    sang(n / factor, luu);
}


void solve(){

    
    long long n;
    cin >> n;
    vector<long long> luu;

    sang(n, luu);


    sort(luu.begin(), luu.end());
    luu.erase(unique(luu.begin(), luu.end()), luu.end());


    cout << luu.size() << "\n";

    



}








