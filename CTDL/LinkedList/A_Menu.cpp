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
#include <stdlib.h>
using namespace std;
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define all(a) a.begin(),a.end()
#define all1(a) a+1,a+n+1
long long INF = (long long)1e9;

struct Node{
    int data;
    Node *next;    
};

typedef struct Node* node;


// Tao node moi, cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x){
    node tmp = new Node();
    tmp->data=x;
    tmp->next=NULL; //nullptr
    return tmp;
}

bool empty(node a){
    return a == NULL;
}

int size(node a){
    int cnt=0;
    while (a!=NULL){
        cnt++;
        a=a->next; // vi a khong phai la tham chieu
    }
    return cnt;
}


void insertF(node &a, int x){  // &a la truyen tham chieu a, co the thay doi
    node tmp=makeNode(x);

    if (a==NULL) a=tmp;
    else{
        tmp->next=a;
        a=tmp;
    }
}

void insertL(node &a, int x){
    node tmp=makeNode(x);
    if (a==NULL) a=tmp;
    else{
        node p=a;
        while (p->next != NULL) p=p->next;

        p->next=tmp;
    }
}

// them vao vi tri bat ki
void insertM(node &a, int x, int pos){
    node tmp=makeNode(x);
    int n=size(a);

    if (pos<=0 || pos > n+1) return;
    if (a==NULL) a=tmp;
    else{
        if (pos==1) {
            insertF(a,x);
            return;
        }
        if (pos==n+1) {
            insertL(a,x);
            return;
        }

        node p=a;
        for (int i=1; i<pos-1; i++){
            p=p->next;
        }
        tmp->next=p->next;
        p->next=tmp;

    }
}

void deleteF(node &a){
    if (a==NULL) return;
    a=a->next;
}

void deleteL(node &a){
    if (a==NULL) return;
    node sau=a, truoc=NULL;
    while (sau->next != NULL){
        truoc=sau;
        sau=sau->next;
    }

    if (truoc==NULL) a=NULL;
    else truoc->next=NULL;


}

void deleteM(node &a, int pos){

    int n=size(a);

    if (pos <= 0 || pos > n) return;

    if (pos==1) { deleteF(a); return; }
    if (pos==n+1) { deleteL(a); return; }

    node p=a, truocp=NULL;
    for (int i=1; i<pos; i++){
        truocp=p;
        p=p->next;
    }
    if (truocp==NULL) a=a->next;
    else truocp->next=p->next;
}


void putNode(node a){
    cout << "------------------------\n";
    while (a != NULL){
        cout << a->data << ' ';
        a = a->next;
    }
}


int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    #endif
 

    node head=NULL;
    bool kt=true; int x,pos;
    while (kt){
        // TextColor(1);
        system("color 4");
        cout << "------------------------MENU------------------------\n";
        cout << "1. Chen phan tu o dau\n";
        cout << "2. Chen phan tu o cuoi\n";
        cout << "3. Chen phan tu o giua\n";
        cout << "4. Xoa phan tu o dau\n";
        cout << "5. Xoa phan tu o cuoi\n";
        cout << "6. Xoa phan tu o giua\n";
        cout << "7. Duyet\n";
        cout << "8. Kt rong\n";
        cout << "9. Size\n";
        cout << "10. KET THUC\n";
        cout << "----------------------------------------------------\n";
        int option; cin >> option;
        if (option == 1){
            cin >> x; insertF(head,x);
        }
        if (option == 2){
            cin >> x; insertL(head,x);      
        }
        if (option == 3){
            cout << "x: "; cin >> x; cout << "\n";
            cout << "pos: "; cin >> pos; cout << "\n";
            insertM(head,x,pos);
        }
        if (option == 4){
            deleteF(head);
        }
        if (option == 5){
            deleteL(head);
        }
        if (option == 6){
            cout << "pos: "; cin >> pos;
            deleteM(head,pos);
        }
        if (option == 7){
            putNode(head);
        }
        if (option == 8){
            cout << ((empty(head))?"YES\n":"NO\n");
        }
        if (option == 9){
            cout << size(head) << "\n";
        }
        if (option == 10){
            kt=false;
        }
    }

    cerr << "Time elapsed: " << TIME << "s.\n";
    cerr << "ducminh" << "\n";
    return 0;
}
