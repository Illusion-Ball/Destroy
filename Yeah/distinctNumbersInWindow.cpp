vector<int> Solution::dNums(vector<int> &A, int k) {
    vector<int> ans;
    
    if (k > A.size()) {
        return ans;
    }
    
    unordered_map<int, int> count;
    int distinctCount = 0;
    
    for (int i = 0; i < k; i++) {
        if (!count[A[i]]) {
            distinctCount++;
        }
        count[A[i]]++;
    }
    
    ans.push_back(distinctCount);
    
    for (int i = k; i < A.size(); i++) {
        count[A[i - k]]--;
        if (!count[A[i - k]]) {
            distinctCount--;
        }
        if (!count[A[i]]) {
            distinctCount++;
        }
        count[A[i]]++;
        
        ans.push_back(distinctCount);
    }
    
    return ans;
}
