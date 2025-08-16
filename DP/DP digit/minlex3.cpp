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
const long long MODD[] = {(long long)220220061,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=1e5+9;
const long long LOG=24;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("GOLD");



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

string L,R;
int len2=0, len1=0, len=0;
long long k;
bool nt[109];
short dp[10][10002][91][2][2];
int anstam[10];
string ans="";
void sang(int n){
    nt[1]=1;
    for (int i=2; i*i<=n; i++){
        for (int j=i*i; j<=n; j+=i){
            nt[j]=1;
        }
    }
}

bool try1(int pos, int du, int sum, int okl, int okr){

    if (pos>=len) {
        return (du==0 && !nt[sum]);
    }

    short &memo=dp[pos][du][sum][okl][okr];
    if (memo!=-1) {
        // if (!nt[sum] && du==0) ans=min(ans,memo);
        return memo;
    }
    memo=0;

    int mn=0;
    int mx=0;

    if (okl) mn=L[pos]-'0';
    else mn=0;
    if (okr) mx=R[pos]-'0';
    else mx=9;

    for (int c=mn; c<=mx; c++){
        if (pos==0 && c==0) continue;
        if (try1(pos+1,(du*10+c)%k,sum+c,okl&&(c==L[pos]-'0'),okr&&(c==R[pos]-'0'))) {
            anstam[pos]=c;
            memo=1;
            return true;
        }
        // memo=try1(pos+1,(du*10+c)%k,sum+c,okl|(c>L[pos]-'0'),okr|(c<R[pos]-'0'))*10+c;
        // cout << memo << ' ' << mn << ' ' << mx << ' ' << pos << "\n";
        // if (!nt[sum+c] && (du*10+c)%k==0 && pos>=len1-1) {
        //     // cout << memo << "\n";
        //     // cout << L << ' ' << R << ' ' << k << "\n";
        //     ans=min(ans,memo);
        // }
    }
    // cout << memo << ' ' << du << ' ' << sum << ' ' << mn << ' ' << mx << "\n";
    memo=0;
    return false;
}
void solve(){
    sang(100);
    // dp[pos][du][sum][okl][okr];
    

    while (cin >> L >> R >> k){
        if (k<=1e4) {
            len2=R.length();
            len1=L.length();
            ans="";
            bool ok=0;
            for (int len3=len1; len3<=len2; len3++){
                len=len3;
                memset(dp,-1,sizeof dp);
                if (try1(0,0,0,(len3==len1),(len3==len2))){
                    string tam="";
                    for (int i=0; i<len; i++){
                        tam.push_back(char('0'+anstam[i]));
                    }
                    if (!ok || tam<ans){
                        ans=tam;
                        ok=1;
                    }
                }
            }
            if (!ok) cout << -1 << "\n";
            else cout << ans << "\n";
        }
        else {
            int l=stoi(L);
            int r=stoi(R);
            long long bg=k*(l/k);
            if (bg<l) bg+=k;

            bool ok=0;
            while (bg<=r){
                long long m=bg;
                int sum=0;
                string tam="";
                while (m>0){
                    sum+=(m%10);
                    tam.push_back(char('0'+(m%10)));
                    m/=10;
                }
                reverse(all(tam)); 
                if (!nt[sum] && (!ok || tam<ans)){
                    ans=tam;
                    ok=1;
                } 
                bg+=k;
            }
            if (!ok) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }

}




