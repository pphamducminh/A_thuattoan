// LCA

long long p[20][200005];

void DFS(int u){
    for (int i=0; i<a[u].size(); i++){

        int v=a[u][i];
        if (p[0][u] != v){
            p[0][v]=u;
            luu[v]=luu[u]+1;
            for (int i=1; i<=mlift; i++){
                p[i][v]= p[i-1][p[i-1][v]];
            }
            DFS(v);
        }
    }
}




int LCA(int u, int v){


    if (luu[u]<luu[v]) swap(u,v);

    int diff = luu[u]-luu[v];
    for (int i=0; i<=mlift; i++){
        if ((diff>>i) & 1){
            u=p[i][u];
        } 
    }
    // cout << u << ' ' << v << "\n";

    if (u==v) return u;




    for (int i=mlift; i>=0; i--){
        if (p[i][u]!=p[i][v]){
            u=p[i][u];
            v=p[i][v];
        }
    }




    return p[0][u];


}

int lifting(int u, int k){
    for (int i=0; i<=mlift; i++){
        if ((k>>i) & 1){
            u=p[i][u];
        }
    }

    return u;
}
