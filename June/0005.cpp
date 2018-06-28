class Solution {
public:
    void updateLongestPalindrome(string &s, int curStart, int curEnd, int &bestStart, int &bestEnd) {
        while (curStart >= 0 && curEnd < s.length() && s[curStart] == s[curEnd]) {
            int curLength = curEnd - curStart + 1;
            int bestLength = bestEnd - bestStart + 1;
            if (curLength > bestLength) {
                bestStart = curStart;
                bestEnd = curEnd;
            }
            curStart--;
            curEnd++;
        }
    }
    
    string longestPalindrome(string s) {
        int bestStart = 0;
        int bestEnd = -1;
        for (int i = 0; i < s.length(); i++) {
            updateLongestPalindrome(s, i - 1, i, bestStart, bestEnd);
            updateLongestPalindrome(s, i, i, bestStart, bestEnd);
        }
        return s.substr(bestStart, bestEnd - bestStart + 1);
    }
};
