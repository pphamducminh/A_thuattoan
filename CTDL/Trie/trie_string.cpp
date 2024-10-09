struct Trie {
    struct Node{

        Node* child[10];
        int cnt,exist;


        Node() {
            for (int i = 0; i < 10; i++) child[i] = nullptr;
            cnt=exist=0;
        }
    };

    Node* root= new Node();

    void insert(string x){
        Node* p=root;
        for (char ch: x){

            int c=ch-'0';
            if (p->child[c]==nullptr){
                p->child[c]=new Node();
            }
            p=p->child[c];
            p->cnt++;
        }
        p->exist++;
    }


    int cnt_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - '0';
            if (p->child[c] == nullptr) return false;
            p = p->child[c];
        }
        return p->exist;
    }
};