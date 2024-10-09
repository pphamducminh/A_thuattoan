void dijkstra(int x){

    for (int i=1; i<=n; i++){
        luu[i]=INF;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    q.push({0,x});
    luu[x]=0;

    while (q.empty()==false){

        int u=q.top().second, du=q.top().first; q.pop();

        if (du>luu[u]) continue;

        // cout << luu[u] << ' ' << u << "\n";


        for (auto tam: a[u]){

            int v=tam.first, m=tam.second;


            // cout << u << ' ' << v << ' ' << m << ' ' << luu[u] << ' ' << luu[v] << "\n";

            if (luu[v]>luu[u]+m){
                luu[v]=luu[u]+m;

                q.push({luu[v],v});
            }


        }
    }


}
