//******************/
//*   I<3   C++    */
//*  I WANT ANY AC */
//* I LOVE PROGRAM!*/
//*IT'S INTERESTING*/
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
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <deque>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define file(name)        freopen(name".inp", "r", stdin);\
                          freopen(name".out", "w", stdout);
#define ordered_set       tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define TIME              (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a)            a.begin(),a.end()
#define endl              "\n"
#define all1(a)           a+1,a+n+1
#define unordered_map     map
#define signed            int32_t                  
#define a                 first
#define b                 second
// #define push_back   emplace_back
// #define gcd(a,b)    __gcd(a,b);
// #define lcm(a,b)    (a*b)/gcd(a,b);

const long long INF = (long long)1e9;
const long long MOD = (long long)1e9+7;
const long long MODD = 123456789; /// 998244353
const long long maxN = 18;
const long long LOG = 30;


///--------------------------------


void solve();

signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        file("ducminh");
    #endif

    // file("TONGBP");



    
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



struct Node {


        Node* child[2];
        int cnt;


        Node() {
            child[0]=child[1]=nullptr;
            cnt=0;
        }


    


};
Node* root=new Node();

    void insert(long long x){
        Node* p=root;
        for (int j=LOG; j>=0; j--){
            int b=(x>>j)&1;

            if (p->child[b] == nullptr){
                p->child[b] = new Node();
            }

            p=p->child[b];
            p->cnt++;
        }
    }
    void erase(long long x){
        Node* p=root;
        for (int j=LOG; j>=0; j--){
            int b=(x>>j)&1;

            
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

void solve(){

    

    long long n;
    cin >> n;

    insert(0);
    for (int i=1; i<=n; i++){
        char choose;
        int x;
        cin >> choose >> x;

        if (choose=='+') insert(x);
        if (choose=='-') erase(x);
        if (choose=='?') cout << query(x) << "\n";


    }


}

















