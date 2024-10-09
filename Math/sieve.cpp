void sang(int n) {
    fill (nt, nt + n, false);
    for (int i = 2; i < n; ++i) {
        if (!nt[i]) prime.push_back (i);
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            nt[i * prime[j]] = true; cnt++;
            if (i % prime[j] == 0) break; 
        }
    }
}
