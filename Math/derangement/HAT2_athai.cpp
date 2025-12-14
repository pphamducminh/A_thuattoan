#include <bits/stdc++.h>



// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC optimize("Ofast","inline","no-stack-protector")
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
const long long MODD[] = {(long long)1e9+19972207,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=3e5+2;
const long long LOG=18;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("permutations");



    int t;

    // cin >> t;

    t=1;


    while (t--){
        solve();
    }
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------


long long n,m;
long long d[1000009];

void add(long long &a, long long b){
    a+=b;
    while (a>=MOD) a-=MOD;
}


long long binpow(long long a, long long b){
 
    long long ans=1;
 
    while (b){
        if (b&1) ans=(ans*a)%MOD;
 
        a=(a*a)%MOD;
        b>>=1;
    }
 
    return ans%MOD;
}
long long fac[1000009], ifac[1000009];
void genfac(int N){

    fac[0]=1;
    for (int i=1; i<=N; i++){
        fac[i]=fac[i-1]*i%MOD;
    }

    // nghich dao cua n!
    ifac[N]=binpow(fac[N],MOD-2);

    for (int i=N; i>=1; i--){
        ifac[i-1] = ifac[i] * i % MOD;
    }
}

// n! / (k! * (n - k)!)

long long combine(int n, int k){

    assert(n >= k);
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void solve(){
    cin >> n >> m;
    genfac(n+2);
    d[0]=1;
    d[1]=0;
    for (int i=2; i<=n; i++){
        d[i]=((i-1)*(d[i-1]+d[i-2])%MOD)%MOD;
    }
    long long ans=0;
    for (int i=0; i<=m; i++){
        add(ans,(combine(n,i)*d[n-i])%MOD);
    }
    cout << ans;
}







