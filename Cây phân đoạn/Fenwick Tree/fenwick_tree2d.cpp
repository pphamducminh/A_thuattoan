long long pre[2000009];
long long pre1[2009][2009];
int n,m;
int a[maxN][maxN];
long long bit[maxN][maxN];




long long convert1d(int i, int j){

    return (i-1)*m+j;
}



void update(int p1, int p2,  int val){

    for (int i=p1; i<=n; i+= i&-i){
        for (int j=p2; j<=m; j+= j&-j){

            bit[i][j]+=val;
        }
    }
}

long long get(int p1, int p2){

    long long ans=0;
    for (int i=p1; i; i-= i&-i){
        for (int j=p2; j; j-= j&-j){

            ans+=bit[i][j];
        }
    }
    return ans;
}


long long pref2d(int u, int v, int x ,int y){

    return get(x,y)-get(x,v-1)-get(u-1,y)+get(u-1,v-1);
}