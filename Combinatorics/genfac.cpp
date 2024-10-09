void genfac(int N){

    fac[0]=1;
    for (int i=1; i<=N; i++){
        fac[i]=fac[i-1]*i%MOD;
    }

    // nghich dao cua n!
    ifac[N]=binpow(fac[N],MOD-2);

    for (int i=N; i>=1; i--){
        ifac[i-1] = ifac[i] * i % MOD;
    }
}

// n! / (k! * (n - k)!)

long long combine(int n, int k){

    assert(n >= k);
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}