    int dep[200009], luu[200009], in[200009],  out[200009], ti=0;
    long long p[20][200009];

    void DFS(int u){

        in[u]=++ti;
        for (int i=0; i<a[u].size(); i++){

            int v=a[u][i];
            if (p[0][u] != v){
                p[0][v]=u;
                dep[v]=dep[u]+1;
                for (int i=1; i<=LOG; i++){
                    p[i][v]= p[i-1][p[i-1][v]];
                }
                DFS(v);
            }
        }
        out[u]=++ti;
    }

    bool is_ancestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }


    int lca(int u, int v){


        if (dep[u]<dep[v]) swap(u,v);

        int diff = dep[u]-dep[v];
        for (int i=0; i<=LOG; i++){
            if ((diff>>i) & 1){
                u=p[i][u];
            } 
        }
        // cout << u << ' ' << v << "\n";

        if (u==v) return u;


        for (int i=LOG; i>=0; i--){
            if (p[i][u]!=p[i][v]){
                u=p[i][u];
                v=p[i][v];
            }
        }

        return p[0][u];


    }



    bool inpath(int u, int v, int x) {
        int lca_uv = lca(u, v);
        // cout << lca_uv << "\n";

        return is_ancestor(lca_uv, x) && (is_ancestor(x, u) || is_ancestor(x, v));
    }
    int getpath(int u, int v) {
        int lca_uv = lca(u, v);
        

        return luu[u]+luu[v]-2*luu[lca_uv];
    }