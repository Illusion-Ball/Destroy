class Solution {
public:
    int match(string &str, string &pattern, int i, int j, vector<vector<int> > &dp) {
        if (j == pattern.length()) {
            return i == str.length();
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool firstMatch = i < str.length() && (str[i] == pattern[j] || pattern[j] == '.');
        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            dp[i][j] = match(str, pattern, i, j + 2, dp) || 
                      (firstMatch && match(str, pattern, i + 1, j, dp));
        } else {
            dp[i][j] = firstMatch && match(str, pattern, i + 1, j + 1, dp);
        }
        return dp[i][j];
    }
    
    bool isMatch(string str, string pattern) {
        vector<vector<int> > dp(str.length() + 1, vector<int> (pattern.length() + 1, -1));
        return (bool) match(str, pattern, 0, 0, dp);
    }
};
