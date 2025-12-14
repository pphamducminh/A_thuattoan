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




const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD[] = {(long long)998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=2e5+5;
const long long LOG=256;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("colorball");




    int t;

    // cin >> t;

    t=1;


    while (t--){
        solve();
    }
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------

long long n;
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long mul(long long a, long long b, long long mod) {
    return (long long)((__int128)a * b % mod);
}

long long binpow(long long a, long long d, long long mod) {
    long long r = 1;
    while (d) {
        if (d & 1) r = mul(r, a, mod);
        a = mul(a, a, mod);
        d >>= 1;
    }
    return r;
}

bool nt(long long n) {
    if (n < 2) return false;
    for (long long p : {2ull,3ull,5ull,7ull,11ull,13ull,17ull,19ull,23ull,29ull,31ull,37ull})
        if (n % p == 0) return n == p;
    long long d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }

    long long bases[] = {2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};
    for (long long a : bases) {
        if (a % n == 0) continue;
        long long x = binpow(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool ok = true;
        for (long long r = 1; r < s; ++r) {
            x = mul(x, x, n);
            if (x == n-1) { ok = false; break; }
        }
        if (ok) return false;
    }
    return true;
}

std::mt19937_64 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

long long rho(long long n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    long long c = std::uniform_int_distribution<long long>(1, n-1)(rng);
    long long x = std::uniform_int_distribution<long long>(0, n-1)(rng);
    long long y = x;
    long long d = 1;
    auto f = [&](long long v){ return (mul(v, v, n) + c) % n; };
    while (d == 1) {
        x = f(x);
        y = f(f(y));
        long long diff = x > y ? x - y : y - x;
        d = gcd(diff, n);
        if (d == n) return rho(n);
    }
    return d;
}

void factor1(long long n, vector<long long> &res) {
    if (n == 1) return;
    if (nt(n)) {
        res.push_back(n);
        return;
    }
    long long d = rho(n);
    factor1(d, res);
    factor1(n / d, res);
}

vector<long long> factor(long long n) {
    vector<long long> res;
    factor1(n, res);
    sort(res.begin(), res.end());
    return res;
}
void solve(){
   
    cin >> n;

    if (n==1) return cout << 1, void();
    vector<long long> luu=factor(n);



}



