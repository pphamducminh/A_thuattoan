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
const int maxN=5e5+9;
const long long LOG=30;
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

int n;
long long sl=1, sum=1, mul=1;
long long x[100009],k[100009], pre[100009], suf[100009];
 
long long phi(long long n) {
    long long ans=n;
    for (int i=2; i*i<=n; i++)
        if (n%i==0) {
            ans-=ans/i;
            while (n%i==0) {
                n/=i;
            }
        }
 
    if (n>1)
        ans-=ans/n;
 
    return ans;
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
long long binpow1(long long a, long long b){
 
    long long ans=1;
 
    while (b){
        if (b&1) ans=(ans*a)%(MOD-1);
 
        a=(a*a)%(MOD-1);
        b>>=1;
    }
 
    return ans%(MOD-1);
}
void solve(){
    cin >> n;
 
    long long sumk=1;
    for (int i=1; i<=n; i++){
        cin >> x[i] >> k[i];
 
        (sl*=(k[i]+1))%=MOD;
        // sum1=sumj(1,k) x^j
        long long sum1=(binpow(x[i],k[i]+1)-x[i]+MOD*MOD)%MOD*binpow(x[i]-1,MOD-2)%MOD;
        sum1++;
        (sum*=sum1)%=MOD;
 
        // cout << x[i] << ' ' << k[i] << ' ' << sum1 << "\n";
        // (sumk*=(k[i]+1))%=(MOD-1);
    }
    pre[0]=1;
    for (int i=1; i<=n; i++){
        pre[i]=pre[i-1]*(k[i]+1)%(MOD-1);
    }
    suf[n+1]=1;
    for (int i=n; i>=1; i--){
        suf[i]=suf[i+1]*(k[i]+1)%(MOD-1);
    }
 
    for (int i=1; i<=n; i++){
        // (sumk*=binpow1(k[i]+1,MOD-3)%(MOD-1))%=(MOD-1);
        // a^k % MOD = a^(k%(MOD-1)) %MOD
        long long mul1=binpow(x[i],k[i]*(k[i]+1)/2)%MOD;
        sumk=pre[i-1]*suf[i+1]%(MOD-1);
        (mul*=binpow(mul1,sumk))%=MOD;
 
        // cout << mul1 << ' ' << binpow(x[i],k[i]*(k[i]+1)/2) << ' ' << k[i]*(k[i]+1)%(MOD-1)*binpow1(2,MOD-3)%(MOD-1) << "\n";
        // cout << mul1 << ' ' << sumk << "\n";
 
        // (sumk*=(k[i]+1))%=(MOD-1);
    }
 
 
 
    cout << sl << ' ' << sum << ' ' << mul << "\n";
}
 
 







