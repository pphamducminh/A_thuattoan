long long mul(long long a, long long b, long long M)
{
    if (b == 0)
        return 0;

    long long t = mul(a, b / 2, M) % M;

    if (b & 1)
        return ((t + t) % M + a % M) % M;
    else
        return (t + t) % M;
}


long long m=0;

struct matran{
    long long X[2][2];
    friend matran operator * (matran a, matran b){
        matran c;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                c.X[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    c.X[i][j] += (a.X[i][k]%m * b.X[k][j]%m)%m;
                    c.X[i][j] %= m;
                }
            }
        }
        return c;
    }
};

matran binpow(matran a, long long n){
    if(n == 1){
        return a;
    }
    matran tmp = binpow(a, n / 2);
    if(n % 2 == 1){
        return tmp * tmp * a;
    }
    else{
        return tmp * tmp;
    }
}