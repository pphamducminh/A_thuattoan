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
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC optimize("Ofast","inline","no-stack-protector")


using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
#define ll long long

const long long INF=1e9;
const long long MOD=1e9+7;
const long long MODD=998244353; // 998244353
const int maxN=1e6+9;
const short LOG=19;


//------------------------



void solve();
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("boxes");



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

int n,m,q;
long long val[100009];
vector<int> a[100009];


struct Trie {
    struct Node{

        Node* child[2];
        int cnt,exist;


        Node() {
            for (int i = 0; i < 2; i++) child[i] = nullptr;
            cnt=0;
        }
    };

    Node* root= new Node();

    void insert(int x){
        Node* p=root;
        for(int i=LOG; i>=0; i--){

            int b=(x>>i)&1;

            if (p->child[b]==nullptr){
                p->child[b]=new Node();
            }
            p=p->child[b];
            p->cnt++;
        }

    }
    void erase(int x){
        Node* p=root;
        for(int i=LOG; i>=0; i--){

            int b=(x>>i)&1;

            if (p->child[b]==nullptr){
                p->child[b]=new Node();
            }
            p=p->child[b];
            p->cnt--;
        }

    }


    long long query(long long d){
        Node* p=root; long long ans=0;
        for (int j=LOG; j>=0; j--){
            int b=(d>>j)&1;

            if (p->child[!b]!=nullptr && p->child[!b]->cnt>0){
                ans+=(1<<j); p=p->child[!b];
            }
            else{
                p=p->child[b];
            }
        }
        return ans;
    }
};


Trie aa;


long long sumxor[100009], cntchild[100009], ans[100009];
vector<int> luu[100009];



void predfs(int u, int par){
    sumxor[u]^=val[u];

    cntchild[u]=1;    
    for (int x: a[u]){
        if (x==par) continue;


        sumxor[x]=sumxor[u];
        predfs(x,u);
        cntchild[u]+=cntchild[x];
    }

}

void sack(int u, int par, int op){

    int bigchild=-1;

    for (int x: a[u]){
        if (x==par) continue;

        if (bigchild==-1 || cntchild[x]>cntchild[bigchild]) bigchild=x;
    }


    for (int x: a[u]){
        if (x!=par && x!=bigchild){
            sack(x,u,0);
        }
    }

    if (bigchild!=-1) sack(bigchild,u,1), luu[u]=luu[bigchild];
    else luu[u].clear();

    luu[u].push_back(sumxor[u]);
    aa.insert(sumxor[u]);

    // max (s[u]^s[v]^a[x])
    ans[u]=max(ans[u],aa.query(sumxor[u]^val[u]));


    for (int x: a[u]){
        if (x!=par && x!=bigchild){
            for (int v: luu[x]){
                ans[u]=max(ans[u],aa.query(v^val[u]));
            }

            for (int v: luu[x]){
                luu[u].push_back(v);
                aa.insert(v);
            }
        }
    }

    if (!op) 
        for (int v: luu[u]){
            aa.erase(v);
        }
}

void dfs(int u, int par){
    for (int x: a[u]){
        if (x!=par) {
            dfs(x,u);
            ans[u]=max(ans[u],ans[x]);
        }
    }

    ans[u]=max(ans[u],val[u]);
}


void solve(){

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> val[i];
    }

    for (int i=2; i<=n; i++){
        int x;
        cin >> x;

        a[i].push_back(x);
        a[x].push_back(i);
    }


    predfs(1,1);
    sack(1,1,1);
    dfs(1,1);


    // cout << (4^2^1^4) << "\n";
    // cout << cntchild[8] << "\n";


    for (int i=1; i<=n; i++){
        cout << ans[i] << "\n";
    }

}
 
 
 







