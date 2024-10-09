    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i*1LL, k); ++j) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }
 
 