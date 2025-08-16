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
const long long LOG=18;
const double eps = 1e-7;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("PNUM");



    int t;

    cin >> t;

    // t=1;

    while (t--){
        solve();
    }

    cerr << "Time: " << TIME << "s.\n";
    cerr << "ducminh";
    return 0;
}

/// -------------- PROBLEM SOLUION --------------------

struct minh{
    int oka,okb,okc;
    int carry,a,b,c;
};

long long n;
int N[18];
int dp[18][3][2][2][2];
minh truoc[18][3][2][2][2];
vector<long long> ansa,ansb,ansc;

bool cmp(bool ok, int a, int b){
    if (b>a) return true;
    if (b<a) return false;

    return ok;
}

long long max3(long long x){
    long long cur=1;
    while (cur*3<=x) cur*=3;
    return cur;
}
void tach(long long x, vector<long long>& ans, int k){
    if (!x) return;
    if (x%2==0) tach(x/2,ans,k+1);
    else {
        long long mx3=max3(x);
        ans.push_back(mx3*(1ll<<k));
        tach(x-mx3,ans,k);
    }
}
void solve(){
    cin >> n;

    int sz=0;
    while (n>0){
        N[++sz]=n%10;
        n/=10;
    }


    memset(dp,-1,sizeof dp);
    dp[0][0][0][0][0]=0;
    for (int i=0; i<sz; i++){
        for (int carry=0; carry<=2; carry++){
            for (int oka=0; oka<2; oka++) {
                for (int okb=0; okb<2; okb++) {
                    for (int okc=0; okc<2; okc++) {
                        for (int a=0; a<=9; a++){
                            for (int b=0; b<=9; b++){
                                for (int c=0; c<=9; c++){
                                    if ((carry+a+b+c)%10!=N[i+1] || dp[i][carry][oka][okb][okc]<0) continue;


                                    if (dp[i][carry][oka][okb][okc]+a+b+c>dp[i+1][(carry+a+b+c)/10][oka || (a!=0)][cmp(okb,a,b)][cmp(okc,b,c)]) {
                                        dp[i+1][(carry+a+b+c)/10][oka || (a!=0)][cmp(okb,a,b)][cmp(okc,b,c)]=dp[i][carry][oka][okb][okc]+a+b+c;
                                        truoc[i+1][(carry+a+b+c)/10][oka || (a!=0)][cmp(okb,a,b)][cmp(okc,b,c)]={oka,okb,okc,carry,a,b,c};
                                    }
                                }
                            }
                        }
                    }     
                }               
            }
        }
    }

    if (dp[sz][0][1][1][1]==-1) return cout << -1 << "\n", void();
    long long numa=0, numb=0, numc=0;
    minh cur=truoc[sz][0][1][1][1];
    int cnt=sz;
    while (cnt){
        numa=numa*10+cur.a;
        numb=numb*10+cur.b;
        numc=numc*10+cur.c;

        cur=truoc[cnt-1][cur.carry][cur.oka][cur.okb][cur.okc];
        cnt--;
    }

    ansa.clear();
    ansb.clear();
    ansc.clear();

    tach(numa,ansa,0);
    tach(numb,ansb,0);
    tach(numc,ansc,0);
    cout << ansa.size() << ' ' << ansb.size() << ' ' << ansc.size() << ' ';
    for (long long x: ansa) cout << x << ' ';
    for (long long x: ansb) cout << x << ' ';
    for (long long x: ansc) cout << x << ' ';
    cout << "\n";
}








