//******************/
//*   I<3   C++    */
//*  I WANT ANY AC */
//* I LOVE PROGRAM!*/
//*IT'S long longERESTING*/
//* I LOVE PROGRAM!*/
//*  IN CONTESTS   */
//*   GET SCORE    */
//*    AC CODE     */
//*     LET'S      */
//*      GO        */
//*  Written by:   */
//*   Duc Minh     */










#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <math.h>
using namespace std; 
#define all(a) a.begin(),a.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define ll long long
// #define push_back emplace_back
long long INF = (long long)1e18;
long long MOD = 1000000007;
// vector<vector<long long>> a(200009),backa(200009);  // khong trong so


// unordered_map<long long,vector<long long>> a;
vector<pair<long long,long long>> a[200009],aback[200009];
// vector<pair<long long, pair<long long, long long>>> a[100009];
// char a[1009][1009];
// long long a[1009][1009];
bool visited[200009];
long long luu[200009],luu1[200009],luuback[200009],maxvet[100009],buocdi[100009],thu[100009];


// unordered_map<long long,long long> luu;

///--------------------------------


void solve();

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif


    
    

    
    long long t;


    // cin >> t;
    
    t=1;



    while (t--){
       



        solve();
       

    }

    

    

    cerr << "Time elapsed: " << TIME << "s.\n";
    cerr << "ducminh" << "\n";
    return 0;
}



///--------------------[PROBLEM SOLUTION]--------------------///

long long truoc[200009],c[209][209];
long long n,m,x,y,w,st,en,l=0,kt=0,dem=0,d=0,k,F,ans=0,s,f;
vector<long long> luumang,topo;
long long demluu[200009],demluu1n[200009],demluun1[200009];
long long dx[4]={-1,0,0,1};
long long dy[4]={0,-1,1,0};
long long colo[100009],dd=0;

long long luuu=0,ok=0; long long bb[2009][2009];


vector<long long> mang;
// void dfs(long long x){

//     visited[x]=1; 
//     luuu++; 
//     ans=max(ans,luuu);  mang.push_back(x);

//     if (mang.size()==k) {  for (long long xx: mang) cout << xx << ' '; cout << "\n"; ok=1;}

//     // if (visited[x]) return;



//     for (long long i=0; i<a[x].size(); i++){

//         if (!visited[a[x][i]]) dfs(a[x][i]);
//     }

//     luuu--; mang.pop_back(); visited[x]=true;

//     // cout << "\n" << s << ' ';
// }

// void BFS(long long u){
//     for (long long i=1; i<=n; i++){
//         luu[i]=INF;
//     }
//     visited[u]=true;
//     luu[u]=1;
//     queue<long long> q;
//     q.push(u);
//     while (q.empty()==false){
//         long long v=q.front(); q.pop();
//         visited[v]=true;

//         cout << v << ' ';
//         if (v==f) { ans++; continue;}
//         for (long long i=0; i<a[v].size(); i++){
//             if (visited[a[v][i]]==false){

                
//                 q.push(a[v][i]);
                
//             }
//         }
//     }
// }



vector<pair<int,int>> ke[100005];
bool taken[100005];

void Prim(int s){
    taken[s] = true; // dua s vao cay khung
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q; // min heap
    //duyet danh sach ke cua s
    for(auto it : a[s]){
        if(!taken[it.first]){
            //first : dinh, second : trong so
            Q.push({it.second, it.first});
        }
    }
    ll d = 0;
    int dem = 0;
    while(!Q.empty()){
        pair<int,int> canh = Q.top(); Q.pop(); // canh ngan nhat
        //canh.first : trong so, canh.second = dinh
        int u = canh.second, w = canh.first;
        if(!taken[u]){
            d += w;
            ++dem;
            taken[u] = true;
            //tu u => duyet ds ke
            for(auto it : a[u]){
                if(!taken[it.first]){
                    Q.push({it.second, it.first});
                }
            }
        }
    }
    


            if (dem == n - 1)

                 cout<<d; else 

                       cout<<"IMPOSSIBLE";
}


void solve(){

    long long mm,maxx=-INF,b[200009],ans1=0,h;
    vector<long long> anss;

    long long q;
    cin >> n;

    for (long long i=0; i<=n; i++){
        a[i].clear(); luu[i]=i; luu1[i]=0; visited[i]=false; truoc[i]=-1;
    }

    ans=0;
    
    while (cin >> x >> y >> mm){

        a[x].push_back({y,mm});
        a[y].push_back({x,mm});
    }

    

    Prim(1);
    
}
