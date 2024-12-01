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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("Ofast","inline","no-stack-protector")
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
const long long MODD[] = {998244353,(long long)1e9+2277, (long long)1e9+5277}; // 998244353
const int maxN=1e6+9;
const long long LOG=256;
const double eps = 1e-6;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("CARNAVAL");



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

struct minh{
    int l,r,pos;
};
int n,q,a[200009], blocksz, L=0, R=0, cur=0;
int ans[200009];

minh qr[200009];
int mm[1000009];

bool cmp(minh a, minh b){
    if (a.l/blocksz!=b.l/blocksz) return a.l<b.l;


    return a.r<b.r;
}


void add(int p){
    if (p==0) return;

    if (mm[a[p]]==0) cur++; 
    mm[a[p]]++;
    if (mm[a[p]]==0) cur--; 

}
void erase(int p){
    if (p==0) return;

    if (mm[a[p]]==0) cur++; 
    mm[a[p]]--;
    if (mm[a[p]]==0) cur--; 

}
void mo(int p){
    int l=qr[p].l, r=qr[p].r;

    while (L<l) {
        erase(L);
        L++;
    }
    while (L>l){
        add(L-1);
        L--;
    }

    while (R>r) {
        erase(R);
        R--;
    }
    while (R<r){
        add(R+1);
        R++;
    }
}

void solve(){
 
 
    cin >> n;
    blocksz=sqrt(n);
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> qr[i].l >> qr[i].r;

        qr[i].pos=i;
    }
    sort(qr+1,qr+q+1,cmp);

    for (int i=1; i<=q; i++){
        mo(i);
        ans[qr[i].pos]=cur;
    }
    for (int i=1; i<=q; i++){
        cout << ans[i] << "\n";
    }
 
}
 
 



 