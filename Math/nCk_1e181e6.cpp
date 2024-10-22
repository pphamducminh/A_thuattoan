void genfac(int N){

    // ifac[i]=1/i

    // ifac[0]=1;
    // ifac[1]=1;

    // for (int i=2; i<=N; i++){
    //     ifac[i]=(MOD-(1LL*MOD/i*ifac[MOD%i]%MOD))%MOD;
    // }
    for (int i=0; i<=N; i++){
        ifac[i]=binpow(i,MOD-2);
    }
}

// n! / (k! * (n - k)!)
// n! / (n - k)! = n * (n - 1) * (n - 2) ... (n - k + 1)
// n! / (n - k)! / (k)! = n * (n - 1) * ... (n - k + 1) / k!
// = n / k * (n - 1) / (k - 1) ....
long long combine(long long n, long long k) {
    if (!k)
        return 1;
    
    return 1ll * n % MOD * combine(n - 1, k - 1) % MOD * ifac[k] % MOD;
}
    