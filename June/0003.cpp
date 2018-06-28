class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength = 0;
        int startIndex = 0;
        unordered_map<char, bool> isPresent;
        for (int i = 0; i < s.length(); i++) {
            while (isPresent[s[i]]) {
                isPresent[s[startIndex++]] = false;
            }
            isPresent[s[i]] = true;
            longestLength = max(longestLength, i - startIndex + 1);
        }
        return longestLength;
    }
};
