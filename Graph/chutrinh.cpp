int degree[200009];
bool checkct(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        ++cnt;
        for(int x: a[v]){
            degree[x]--;
            if(!degree[x]) q.push(x);
        }
    }
    // cout << cnt << endl;
    if(cnt == n){
        return false;
    }
    return true;
}
