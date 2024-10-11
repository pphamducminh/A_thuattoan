#include <bits/stdc++.h>

// spring 2008 - Thay Hieu
using namespace std;

#define file(name) freopen(name".inp","r",stdin);\
                    freopen(name".out","w",stdout);
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1


const long long INF=3e18;
const long long MOD=1e9+7;
const long long MODD=998244353;
const int maxN=1e5+9;
const int LOG=60;

//------------------------


void solve();

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

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
    int x1, y1, x2, y2;
};

int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1}; // E S N W
 
 
int n,m,k;
minh a[maxN];

vector<minh> luux,luuy,b;


bool cmp(minh a, minh b){


    if (a.x1==b.x1) {
        if (a.y1==b.y1) return a.y2<b.y2;
        return a.y1<b.y1;
    }
    return a.x1<b.x1;
}

bool cmp1(minh a, minh b){

    if (a.y1==b.y1) {

        if (a.x1==b.x1) return a.x2<b.x2;
        return a.x1<b.x1;
    }
    return a.y1<b.y1;
}


// sweep line


const long double EPS = 1e-9;

struct Event{
    long double x;
    int y, y2, type;
    
    bool operator < (const Event& other) const {
        return x < other.x;
    }
};

struct FenwickTree{
    int n;
    vector<int> s;

    FenwickTree(int n) : n(n), s(n + 5) {
        for (int i = 1; i <= n; i++) s[i] = 0;
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i) s[i] += val;
    }

    int getsum(int i) {
        int res = 0;
        for (; i; i -= i & -i) res += s[i];
        return res;
    }

    int query(int l, int r) {
        return getsum(r) - getsum(l - 1);
    }
};



vector<long double> compress_y;
vector<Event> events;
 
void solve(){
 
    cin >> n >> m >> k;
 
    // if (n>7000 || m>7000) return cout << n*m, void();
 
    for (int i=1; i<=k; i++){
        int x,y;
        char ch;
        cin >> x >> y >> ch;
 
        if (ch=='S') {

            a[i]={1,y,x,y};
            // compress_y.push_back(1);
            // compress_y.push_back(x);
        }
 
        if (ch=='E') {

            a[i]={x,y,x,m};
            // compress_y.push_back(x);
        }
 
        if (ch=='N') {

            a[i]={x,y,n,y};
            // compress_y.push_back(x);
            // compress_y.push_back(n);
        }
 
        if (ch=='W') {


            a[i]={x,1,x,y};
            // compress_y.push_back(x);
        }
 
 
    }


    for (int i=1; i<=k; i++){
        // cout << a[i].x1 << ' ' << a[i].y1 << ' ' << a[i].x2 << ' ' << a[i].y2 << "\n";
        if (a[i].x1==a[i].x2){
            luux.push_back({a[i].x1,a[i].y1,a[i].x2,a[i].y2});
        }
        else{
            luuy.push_back({a[i].x1,a[i].y1,a[i].x2,a[i].y2});
        }
    }

    sort(all(luux),cmp);
    sort(all(luuy),cmp1);

    b.push_back({0,0,0,0});



    vector<pair<int,int>> tam;

    if (luux.size()){
        tam.push_back({luux[0].y1,luux[0].y2});
        // cout << luux[0].x1 << ' ' << luux[0].y1 << ' ' << luux[0].x2 << ' ' << luux[0].y2 << "\n";
        for (int i=1; i<luux.size(); i++){
            // cout << luux[i].x1 << ' ' << luux[i].y1 << ' ' << luux[i].x2 << ' ' << luux[i].y2 << "\n";

            if (luux[i].x1==luux[i-1].x1){
                if (luux[i].y1==luux[i-1].y1 && luux[i].y2==luux[i-1].y2) continue;
                tam.push_back({luux[i].y1,luux[i].y2});
            }
            else{
                int truoc=tam[0].second;
                int ok=1;
                int l=tam[0].first, r=tam[0].second;
                for (int j=1; j<tam.size(); j++){
                    pair<int,int> x=tam[j];
                    if (x.first<=truoc){
                        r=max(r,x.second);
                        truoc=x.second;
                        if (x.first==x.second) truoc++;
                        ok=1;
                    }
                    else{
                        if (x.second<=r) continue;
                        // cout << j << ' ' << l << ' ' << r << "\n";
                        b.push_back({luux[i-1].x1,l,luux[i-1].x2,r});
                        if (x.first > l && x.second > r) ok=1;
                        else ok=0;
                        if (x.first<=r) l=r+1;
                        else l=x.first;  truoc=x.second; r=max(r,x.second);
                        
                    }
                }
                // cout << l << ' ' << r << "\n";
                if (ok) b.push_back({luux[i-1].x1,l,luux[i-1].x2,r});
                tam.clear();
                tam.push_back({luux[i].y1,luux[i].y2});
            }
        }

        if (tam.size()){
            int truoc=tam[0].second;
            int ok=1;
            int l=tam[0].first, r=tam[0].second;
            for (int j=1; j<tam.size(); j++){
                pair<int,int> x=tam[j];
                if (x.first<=truoc){
                    r=max(r,x.second);
                    truoc=x.second;
                    if (x.first==x.second) truoc++;
                    ok=1;
                }
                else{

                    if (x.second<=r) continue;
                    b.push_back({luux[luux.size()-1].x1,l,luux[luux.size()-1].x2,r});
                    if (x.first > l && x.second > r) ok=1;
                    else ok=0;
                    // cout << j << ' ' << l << ' ' << r << ' ' << x.first << ' ' << x.second << ' ' << truoc << "\n";
                    if (x.first<=r) l=r+1;
                    else l=x.first; 
                    truoc=x.second; r=max(r,x.second);
                }
            }
            // cout << l << ' ' << r << "\n";
            if (ok) b.push_back({luux[luux.size()-1].x1,l,luux[luux.size()-1].x2,r});
            tam.clear();
        }
    }



    if (luuy.size()){
        tam.push_back({luuy[0].x1,luuy[0].x2});
        // cout << luuy[0].x1 << ' ' << luuy[0].y1 << ' ' << luuy[0].x2 << ' ' << luuy[0].y2 << "\n";
        for (int i=1; i<luuy.size(); i++){
            // cout << luuy[i].x1 << ' ' << luuy[i].y1 << ' ' << luuy[i].x2 << ' ' << luuy[i].y2 << "\n";

            if (luuy[i].y1==luuy[i-1].y1){
                if (luuy[i].x1==luuy[i-1].x1 && luuy[i].x2==luuy[i-1].x2) continue;
                tam.push_back({luuy[i].x1,luuy[i].x2});
            }
            else{
                int truoc=tam[0].second;
                int ok=1;
                int l=tam[0].first, r=tam[0].second;
                for (int j=1; j<tam.size(); j++){
                    pair<int,int> x=tam[j];
                    if (x.first<=truoc){
                        r=max(r,x.second);
                        truoc=x.second;
                        if (x.first==x.second) truoc++;
                        ok=1;
                    }
                    else{
                        if (x.second<=r) continue;
                        b.push_back({l,luuy[i-1].y1,r,luuy[i-1].y2});
                        if (x.first > l && x.second > r) ok=1;
                        else ok=0;
                        if (x.first<=r) l=r+1;
                        else l=x.first;   truoc=x.second; r=x.second;

                    }
                }
                // cout << l << ' ' << r << "\n";
                if (ok) b.push_back({l,luuy[i-1].y1,r,luuy[i-1].y2});
                tam.clear();
                tam.push_back({luuy[i].x1,luuy[i].x2});
            }
        }

        if (tam.size()){
            int truoc=tam[0].second;
            int ok=1;
            int l=tam[0].first, r=tam[0].second;
            for (int j=1; j<tam.size(); j++){
                pair<int,int> x=tam[j];
                if (x.first<=truoc){
                    r=max(r,x.second);
                    truoc=x.second;
                    if (x.first==x.second) truoc++;
                    ok=1;
                }
                else{
                    if (x.second<=r) continue;
                    // cout << l << ' ' << r << "\n";
                    b.push_back({l,luuy[luuy.size()-1].y1,r,luuy[luuy.size()-1].y2});
                    if (x.first > l && x.second > r) ok=1;
                    else ok=0;
                    if (x.first<=r) l=r+1;
                    else l=x.first;  truoc=x.second; r=x.second;

                }
            }
            // cout << l << ' ' << r << "\n";
            if (ok) b.push_back({l,luuy[luuy.size()-1].y1,r,luuy[luuy.size()-1].y2});
            tam.clear();
        }
    }
















  
    long long ans=0;
    k=b.size()-1;
    for (int i=1; i<=k; i++){
        // cout << b[i].x1 << ' ' << b[i].y1 << ' ' << b[i].x2 << ' ' << b[i].y2 << "\n";


        if (b[i].x1==b[i].x2){
            compress_y.push_back(b[i].x1);
        }
        else{
            compress_y.push_back(b[i].x1);
            compress_y.push_back(b[i].x2);
        }
        
        ans+=max(b[i].x2-b[i].x1,b[i].y2-b[i].y1)+1;
    }  




    sort(compress_y.begin(), compress_y.end());
    compress_y.erase(unique(compress_y.begin(), compress_y.end()), compress_y.end());

    n=compress_y.size();

    for (int i=1; i<=k; i++){
        if (b[i].x1==b[i].x2){
            int yy = lower_bound(compress_y.begin(), compress_y.end(), b[i].x1) - compress_y.begin() + 1;
            events.push_back({b[i].y1 - EPS, yy, 0, 1});
            events.push_back({b[i].y2 + EPS, yy, 0, 2}); 
        }
        else{
            int l = lower_bound(compress_y.begin(), compress_y.end(), b[i].x1) - compress_y.begin() + 1;
            int r = lower_bound(compress_y.begin(), compress_y.end(), b[i].x2) - compress_y.begin() + 1;
            events.push_back({1.0*b[i].y1, l, r, 3}); 
        }
    }



    sort(events.begin(), events.end());

    FenwickTree FT(n * 4); 
    long long res = 0;
    for (auto e : events){
        if (e.type == 1) FT.update(e.y, 1);
        else if (e.type == 2) FT.update(e.y, -1);
        else res += FT.query(e.y, e.y2);
    }
    
    // if (n==5 && m==8 && k==4) return cout << 13, void();


    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=m; j++){
    //         if (mm[i][j]) ans++;
    //     }
    // }
 
    cout << ans-res;
 
}
 









