int n,q;


int a[maxN], st[LOG + 1][maxN];
void preprocess() {
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LOG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}


int log2_floor(int n){
    return n ? __builtin_clzll(1) - __builtin_clzll(n) : -1;
}
int queryMin(int l, int r) {
    int k = log2_floor(r - l + 1);
    // int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}
