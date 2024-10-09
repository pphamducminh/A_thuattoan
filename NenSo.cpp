    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
 
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
