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


    int query(int x) {
        Node* p=root; int ans=0;
        for(int i=LOG; i>=0; i--){

            int b=(x>>i)&1;

            if (p->child[b]!=nullptr && p->child[b]->cnt>0){
                p=p->child[b];
            }
            else {
                ans+=(1<<i);
                p=p->child[!b];
            }
            p->cnt--;
        }
        return ans;
    }
};