    vector<int> f(n+1), up(n+1, INT_MAX);
    up[0] = INT_MIN;
    int ans = 0;
    for (int x: pos) {
        int k = lower_bound(up.begin(), up.end(), x) - up.begin();
        up[k] = x;
        ans = max(ans, k);
    }