// DSU

void init(){
    for(long long i = 1; i <= n; i++){
        truoc[i] = i;
        rnk[i] = 1;
    }
}

long long root(long long u){
    if (truoc[u]==u) return u;
    return truoc[u]=root(truoc[u]);
}


bool hop(long long x, long long y){
    long long u=root(x), v=root(y);

    if (u==v) return false;

    if (rnk[u]<rnk[v]) swap(u,v);

    truoc[v]=u;
    rnk[u]+=rnk[v];

    return true;
}
