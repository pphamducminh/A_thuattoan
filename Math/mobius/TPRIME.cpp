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




const long long INF=(1e9);
const long long MOD=1e9+7;
const long long MODD[] = {(long long)998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=5e5+5;
const long long LOG=20;
const double eps = 1e-9;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif





    int t;

    // cin >> t;

    t=1;


    while (t--){
        solve();
    }
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------

bool nt[100009];
int mu[100009], s[100009];
long long pre[100009];
vector<int> prime;

void prepro(int n){
    for (long long i=0; i<=n; i++){
        mu[i]=1; 
        nt[i]=1;
    }

    for (long long i=2; i<=n; i++){
        if (!nt[i]) continue;
        prime.push_back(i);
        for (long long j=i; j<=n; j+=i) {
            nt[j]=0;
            mu[j]*=-1;
        }

        for (long long j=i*i; j<=n; j+=i*i){
            mu[j]=0;
        }
    }

    for (int p: prime){
        for (int k=1; p*k<=n; k++){
            s[p*k]+=mu[k];
        }
    }

    for (int i=1; i<=n; i++){
        pre[i]=pre[i-1]+s[i];
    }
}   

long long calc_sub1(int n, int m){
    int lim=min(n,m);

    long long ans=0;
    for (int d=1; d<=lim; d++){
        ans+=s[d]*(n/d)*(m/d);
    }
    return ans;
}

long long calc(int n, int m){
    int lim=min(n,m);

    long long ans=0;
    int l=1;
    while (l<=lim){
        long long n1=n/l;
        long long m1=m/l;
        int r1=n/n1;
        int r2=m/m1;

        int r=min({r1,r2,lim});
        ans+=(pre[r]-pre[l-1])*n1*m1;
        l=r+1;
    }
    return ans;
}
void solve() {
    int t; 
    cin >> t;

    prepro(100002);


    while (t--){
        int n,m;
        cin >> n >> m;

        cout << calc(n,m) << "\n";
    }

}









