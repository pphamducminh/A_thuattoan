    for (int i=0; i<=m; i++){
        for (int mask=0; mask<(1<<m); mask++){
            dp[i][mask]=INF;
        }
    }
 
 
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            int d=0;
            for (int k1=0; k1<n; k1++){
                    if (s[i][k1]!=s[j][k1]) d++;
            }
            cost[i][j]=d;
        }
    }
 
 
    for (int i=0; i<m; i++){
 
 
        int d=0;
        for (int j=0; j<n; j++){
            if (s[i][j]=='1') d++;
        }
 
        dp[i][(1<<i)]=d;
    }
 
    for (int mask=0; mask<(1<<m); mask++){
 
        for (int i=0; i<m; i++){
 
            if (!((mask>>i)&1)) continue;
            for (int j=0; j<m; j++){
                if (i==j || !((mask>>j)&1)) continue;
 
                long long d=0;
 
 
                // cout << i << ' ' << j << ' ' << d << "\n";
 
                dp[i][mask]=min(dp[i][mask],dp[j][mask^(1<<i)]+cost[i][j]);
 
                // cout << i << ' ' << j << ' ' << mask << ' ' << dp[i][mask] << "\n";
            }
        }
    }
 
    long long ans = INF;
    for (long long i = 0; i < m; ++i) {
        ans = min(ans, dp[i][(1 << m) - 1]);
    }
 
    cout << ans;
 