void tarjan(long long u){

    low[u]=num[u]=++d;
    st.push(u);

    for (long long x: a[u]){


        if (removed[x]) continue;

        if (!num[x]){

            tarjan(x);
            low[u]=min(low[u],low[x]);
        }
        else low[u]=min(low[u],num[x]);
    }
    

    if (low[u]==num[u]){
        dscc++;
        long long v;
        fi[dscc]=u;
        la[dscc]=st.top();


        do{

            v=st.top();
            in_scc[v]=dscc;
            // sum_scc[dscc]=calc()
            removed[v]=true;
            st.pop();
        } while (v!=u);
    }
}