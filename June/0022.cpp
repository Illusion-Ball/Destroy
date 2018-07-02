class Solution {
    void generateParanthesis(string &cur, vector<string> &ans, int open, int closed, int n) {
        if (closed == n) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            generateParanthesis(cur, ans, open + 1, closed, n);
            cur.pop_back();
        }
        if (closed < open) {
            cur.push_back(')');
            generateParanthesis(cur, ans, open, closed + 1, n);
            cur.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> ans;
        generateParanthesis(cur, ans, 0, 0, n);
        return ans;
    }
};
