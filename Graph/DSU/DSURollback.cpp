vector<pair<int,int>> dscanh;
struct Query {
    string op;
    int u, v;
};
struct Edge {
    int u, v;
    Edge(int a, int b) {
        if(a < b){ u = a; v = b; }
        else { u = b; v = a; }
    }
    bool operator<(const Edge& other) const{
        if(u != other.u) return u < other.u;
        return v < other.v;
    }
};
class DSU_Rollback {
public:
    vector<int> par;
    vector<int> rnk;
    vector<pair<int, int>> history;
    DSU_Rollback(int n){
        par.resize(n+1);
        rnk.resize(n+1, 1);
        for(int i=0;i<=n;i++) par[i] = i;
    }
    int find_set(int u){
        if(par[u] == u) return u;
        return find_set(par[u]);
    }
    void union_set(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if(u == v) return;
        if(rnk[u] < rnk[v]) swap(u, v);
        history.emplace_back(v, par[v]); 
        par[v] = u;
        rnk[u] += rnk[v];
    }
    void rollback(int cp){
        while(history.size() > cp){
            auto [node, prev_par] = history.back();
            history.pop_back();
            rnk[par[node]] -= rnk[node];
            par[node] = prev_par;
        }
    }
    int gethist(){
        return history.size();
    }
};


class SegmentTree {
public:
    int n;
    vector<vector<Edge>> tree;
    SegmentTree(int rnk){
        n = rnk;
        tree.resize(4*n);
    }
    void add_edge(int node, int l, int r, int ql, int qr, Edge edge){
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr){
            tree[node].emplace_back(edge);
            return;
        }
        int mid = (l + r) / 2;
        add_edge(2*node, l, mid, ql, qr, edge);
        add_edge(2*node+1, mid+1, r, ql, qr, edge);
    }
    void tv(int node, int l, int r, DSU_Rollback &dsu, vector<string> &ans, const vector<pair<int,int>> &qr){
        int cp = dsu.gethist();
        for(auto &edge : tree[node]){
            dsu.union_set(edge.u, edge.v);
        }
        if(l == r){
            if(qr[l].first != -1){
                int u = qr[l].first;
                int v = qr[l].second;
                if(dsu.find_set(u) == dsu.find_set(v)){
                    ans[l] = "YES";
                }
                else{
                    ans[l] = "NO";
                }
            }
        }
        else{
            int mid = (l + r) / 2;
            tv(2*node, l, mid, dsu, ans, qr);
            tv(2*node+1, mid+1, r, dsu, ans, qr);
        }
        dsu.rollback(cp);
    }
};
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        dscanh.push_back({u-1,v-1});
    }
    vector<Query> qr1(q);
    for(int i=0;i<q;i++){
        cin >> qr1[i].op >> qr1[i].u >> qr1[i].v;
        qr1[i].u--;
        qr1[i].v--;
    }

    map<Edge, vector<pair<int, int>>> ed;
    map<Edge, int> lst;
    for(auto &[u, v] : dscanh){
        Edge e(u, v);
        lst[e] = -1;
    }
    for(int i=0;i<q;i++){
        string op = qr1[i].op;
        int u = qr1[i].u;
        int v = qr1[i].v;
        Edge e(u, v);
        if(op == "Add"){
            if(lst.find(e) == lst.end()){
                lst[e] = i;
            }

        }
        else if(op == "Remove"){
            if(lst.find(e) != lst.end()){
                int ti = lst[e];
                if(ti == -1){
                    ed[e].emplace_back(0, i-1);
                }
                else{
                    ed[e].emplace_back(ti, i-1);
                }
                lst.erase(e);
            }

        }

    }
    for(auto &[e, ti] : lst){
        if(ti == -1){
            ed[e].emplace_back(0, q-1);
        }
        else{
            ed[e].emplace_back(ti, q-1);
        }
    }
    SegmentTree seg(q);
    for(auto &[e, ti] : ed){
        for(auto &[st, en] : ti){
            seg.add_edge(1, 0, q-1, st, en, e);
        }
    }
    vector<pair<int, int>> qr(q, {-1, -1});
    for(int i=0;i<q;i++){
        if(qr1[i].op == "Ask"){
            qr[i] = {qr1[i].u, qr1[i].v};
        }
    }
    vector<string> ans(q, "NO");
    DSU_Rollback dsu(n);
    seg.tv(1, 0, q-1, dsu, ans, qr);
    for (int i=0;i<q;i++){
        if(qr1[i].op == "Ask"){
            cout << ans[i] << "\n";
        }
    }
}