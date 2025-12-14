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



const long long INF=1e17;
const long long MOD=1e9+7;
const long long MODD[] = {998244353,(int)1e9+2277, (int)1e9+5277}; // 998244353
const int maxN=1e6+9;
const long long LOG=20;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif


    // file("facttree");



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

int n,k;
long long a[5009];
long long dp1[5009], dp2[5009],pre[5009];

long long cost(long long l, long long r){
    return (pre[r]-pre[l-1])*(pre[r]-pre[l-1]);
}

void dpdnc(int l, int r, int optl, int optr){
    if (l>r) return;
    int mid=(l+r)>>1;

    pair<long long,int> best={INF,-1};
    for (int k=optl; k<=min(mid-1,optr); k++){
        best=min(best,{dp1[k]+cost(k+1,mid),k});
    }

    dp2[mid]=best.first;
    int opt=best.second;

    dpdnc(l,mid-1,optl,opt);
    dpdnc(mid+1,r,opt,optr);
}
void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }

    for (int i=0; i<=n; i++){
        dp1[i]=dp2[i]=INF;
    }
    dp1[0]=0;
    for (int t=1; t<=k; t++){
        // for (int i=1; i<=n; i++){
        //     for (int j=0; j<i; j++){
        //         dp2[i]=min(dp2[i],dp1[j]+cost(j+1,i));
        //     }
        // }
        dpdnc(0,n,0,n);
        for (int i=1; i<=n; i++){
            dp1[i]=dp2[i];
        }
    }
    cout << dp2[n];
}





 