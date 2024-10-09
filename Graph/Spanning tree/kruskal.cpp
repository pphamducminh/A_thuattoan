struct canh{
    long long x, y, w;
};
vector<canh> dscanh;
long long parent[200009],sz[200009];
 
//sz[i] : 
void init(){
    for(long long i = 1; i <= n; i++){
        truoc[i] = i;
        sz[i] = 1;
    }
}
 
long long root(long long u){
    if (truoc[u]==u) return u;
    return truoc[u]=root(truoc[u]);
}


long long hop(long long x, long long y){
    long long u=root(x), v=root(y);

    if (u==v) return 0;

    truoc[u]=v;

    return 1;
}
 
bool cmp(canh a, canh b){
    return a.w < b.w;
}

void kruskal(){
    vector<canh> cay;
    ll d = 0;
    for(long long i = 0; i < m; i++){
        if(cay.size() == n - 1)
            break;
        canh tmp = dscanh[i];
        if(Union(tmp.x, tmp.y)){
            d += tmp.w;
            cay.push_back(tmp);
        }
    }
 
 
    if (cay.size() == n - 1)
        cout << d << endl;
    else
        cout << "IMPOSSIBLE\n";
}