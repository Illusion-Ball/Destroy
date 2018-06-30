class Solution {
    string commonPrefix(string &str1, string &str2) {
        int minLength = min(str1.length(), str2.length());
        for (int i = 0; i < minLength; i++) {
            if (str1[i] != str2[i]) {
                return str1.substr(0, i);
            }
        }
        return str1.substr(0, minLength);
    }
    
    string longestCommonPrefix(int l, int r, vector<string> &strs) {
        if (l == r) {
            return strs[l];
        }
        int mid = l + (r - l) / 2;
        string leftPrefix = longestCommonPrefix(l, mid, strs);
        string rightPrefix = longestCommonPrefix(mid + 1, r, strs);
        return commonPrefix(leftPrefix, rightPrefix);
    }
    
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        return longestCommonPrefix(0, (int) strs.size() - 1, strs);
    }
};
