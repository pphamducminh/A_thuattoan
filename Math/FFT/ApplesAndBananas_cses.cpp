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
const long long MODD[] = {(long long)1e9+22071997,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=2e5+5;
const long long LOG=18;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("xorpair");



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

int k,n,m;

using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool inv) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen = cd(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w = 1;
            for (int j = 0; j < len/2; ++j) {
                cd u = a[i+j];
                cd v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) {
        for (cd & x : a) x /= n;
    }
}

vector<long long> convolution(const vector<long long>& A, const vector<long long>& B) {
    int n1 = A.size(), n2 = B.size();
    int n = 1;
    while (n < n1 + n2 - 1) n <<= 1;
    vector<cd> fa(n), fb(n);
    for (int i = 0; i < n1; ++i) fa[i] = cd(A[i], 0);
    for (int i = 0; i < n2; ++i) fb[i] = cd(B[i], 0);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);
    vector<long long> res(n1 + n2 - 1);
    for (int i = 0; i < (int)res.size(); ++i)
        res[i] = (long long)llround(fa[i].real());
    return res;
}
void solve() {
    cin >> k >> n >> m;
    vector<long long> cnta(k+1,0), cntb(k+1,0);
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;

        cnta[x]++;
    }
    for (int i=1; i<=m; i++){
        int x;
        cin >> x;

        cntb[x]++;
    }

    vector<long long> conv=convolution(cnta,cntb);

    for (int w=2; w<=2*k; w++){
        cout << conv[w] << ' '; 
    }
}





