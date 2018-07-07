vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = (int) A.size() - 1;
    int j = (int) B.size() - 1;
    
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({A[i] + B[j], {i, j}});
    
    set<pair<int, int> > exists; 
    
    while (ans.size() < A.size()) {
        auto pairWithSum = pq.top();
        pq.pop();
 
        ans.push_back(pairWithSum.first);
        
        i = pairWithSum.second.first;
        j = pairWithSum.second.second;
        
        if (i - 1 >= 0 && exists.find({i - 1, j}) == exists.end()) {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            exists.insert({i - 1, j});
        }
        if (j - 1 >= 0 && exists.find({i, j - 1}) == exists.end()) {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            exists.insert({i, j - 1});
        }
    }
    
    return ans;
}
