vector<int> tree[maxN*4];
long long a[maxN];
int n,q;

void buildtree(int id, int l, int r){

    if (l==r){
        tree[id].push_back(a[l]);
        return;
    }


    int mid=(l+r)>>1;


    buildtree(id<<1, l, mid);
    buildtree(id<<1|1, mid+1, r);

    merge(all(tree[id<<1]), all(tree[id<<1|1]), back_inserter(tree[id]));
}

long long gettree(int id, int l ,int r, int u, int v, int k){

    if (l>v || r<u) return 0;

    if (u<=l && r<=v){

        return lower_bound(all(tree[id]), k)-tree[id].begin();
    }

    int mid=(l+r)>>1;

    return gettree(id<<1,l,mid,u,v,k) + gettree(id<<1|1, mid+1,r,u,v,k);
}