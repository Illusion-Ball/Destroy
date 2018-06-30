class Solution {
    unordered_map<int, string> digitsMap;
    
    void generateCombinations(string &digits, string &cur, vector<string> &combinations, int index) {
        if (index == digits.length()) {
            combinations.push_back(cur);
            return;
        }
        for (char ch : digitsMap[digits[index] - '0']) {
            cur[index] = ch;
            generateCombinations(digits, cur, combinations, index + 1);
        }
    }
    
public:
    Solution() {
        digitsMap[2] = "abc";
        digitsMap[3] = "def";
        digitsMap[4] = "ghi";
        digitsMap[5] = "jkl";
        digitsMap[6] = "mno";
        digitsMap[7] = "pqrs";
        digitsMap[8] = "tuv";
        digitsMap[9] = "wxyz";
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        string cur = digits;
        generateCombinations(digits, cur, combinations, 0);
        return combinations;
    }
};
