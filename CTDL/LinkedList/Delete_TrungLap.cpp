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
using namespace std;
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
long long INF = (long long)1e9;
// const long long du=1000000007;
// long long w[20],v[20];
// map<long long,long long> q;
// long long n,ans=INF;
// unsigned long long a[200009],pre[200009],x=0,sum=0;
// long long n,h[1000009],j[1000009],b[1000009];
vector<long long> aa;
    map<long long,long long> m;
set<long long> possible_sums;
    
set<vector<long long>> result;
    vector<long long> currentCombination;




struct Node{
    int data;
    Node *next;
};


typedef struct Node* node;
node makeNode(int x){
    node tmp = new Node();
    tmp->data=x;
    tmp->next=NULL; //nullptr
    return tmp;
}

int size(node a){
    int cnt=0;
    while (a!=NULL){
        cnt++;
        a=a->next;
    }
    return cnt;
}

void insertL(node &a, int x){
    node tmp=makeNode(x);

    if (a==NULL) a=tmp;
    else{
        node p=a;
        while (p->next!=NULL){
            p=p->next;
        }

        p->next=tmp;
    }
}

void deleteM(node &a, int pos){
    int n=size(a);
    if (pos<=0 || pos > n+1) return;

    if (a==NULL) return;
    else{
        if (pos==1){
            a=a->next;
            return;
        }
        if (pos==n+1){
            node truoc=NULL, sau=a;
            while (sau->next != NULL){
                truoc=sau;
                sau=sau->next;
            }
            if (truoc==NULL) a=a->next;
            else truoc->next=NULL;
            return;
        }

        node p=a,truoc=NULL;
        for (int i=1; i<pos; i++){
            truoc=p;
            p=p->next;
        }
        if (truoc==NULL) a=a->next;
        else truoc->next=p->next;

    }
}


void duyet(node a){
    while (a!=NULL){
        cout << a->data << ' ';
        a=a->next;
    }
}


signed main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    node head=NULL;   
    int n,x;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> x;

        insertL(head,x);
    }

    node p=head; int cnt=1,d=0;
    while (p->next!=NULL){
        int tam=p->data;
        p=p->next;
        cnt++;
        int tam1=p->data;
        if (tam==tam1) deleteM(head,cnt-d),d++;
        // if (tam==tam1) cout << cnt << ' ';
    }
    cout << "\n";
    // deleteM(head,3);
    duyet(head);
    cerr << "Time elapsed: " << TIME << "s.\n";
    cerr << "ducminh" << "\n";
    return 0;
}
