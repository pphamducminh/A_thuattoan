int tree[maxN*4];
long long a[maxN];
int n,q;



void buildtree(int id, int l, int r){

    if (l==r){

        tree[id]=a[l];
        return;
    }

    int mid=(l+r)>>1;

    buildtree(id<<1,l,mid);
    buildtree(id<<1|1,mid+1,r);

    tree[id]=min(tree[id<<1], tree[id<<1|1]);


}


void updatetree(int id, int l, int r, int u, int v, int val){

    if (l>v || r<u) return;

    if (l==u && r==v){

        tree[id]=val;
        return;
    }

    int mid=(l+r)>>1;

    if (mid>=v) updatetree(id<<1,l,mid,u,v,val);
    else if (mid<u) updatetree(id<<1|1,mid+1,r,u,v,val);

    tree[id]=min(tree[id<<1], tree[id<<1|1]);


}


long long gettree(int id, int l, int r, int u, int v){

    if (l>r) return INF;

    if (u == l && r == v){
 
        return tree[id];
 
    }


    int mid=(l+r)>>1;

    if (v<=mid) return gettree(id<<1,l,mid,u,v);
    else if (u>mid) return gettree(id<<1|1,mid+1,r,u,v);

    else return min(gettree(id<<1,l,mid,u,mid), gettree(id<<1|1,mid+1,r,mid+1,v));


}