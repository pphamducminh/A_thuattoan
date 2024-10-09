for (int i = 1; i <= N; ++i) { 

    while (dq.size() && A[dq.back()] >= A[i]) dq.pop_back();
    

    dq.push_back(i); 
    

       // thì ta sẽ loại bỏ ra khỏi deque 
    if (dq.front() + k <= i) dq.pop_front(); 
    

    if (i >= k) minRange[i] = A[dq.front()]; 
}