int Solution::nchoc(int k, vector<int> &chocolates) {
    priority_queue<int> pq;
    int numOfChocolatesEaten = 0;
    const int MOD = (int) 1e9 + 7;
    
    for (int i = 0; i < chocolates.size(); i++) {
        pq.push(chocolates[i]);
    }
    
    for (int i = 0; i < k && (!pq.empty()); i++) {
        int numOfChocolates = pq.top();
        pq.pop();
        numOfChocolatesEaten = (numOfChocolatesEaten + (numOfChocolates % MOD)) % MOD;
        pq.push(numOfChocolates / 2);
    }
    
    return numOfChocolatesEaten;
}
