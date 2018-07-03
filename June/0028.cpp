class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= (int) haystack.length() - (int) needle.length(); i++) {
            bool isPresent = true;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    isPresent = false;
                    break;
                }
            }
            if (isPresent) {
                return i;
            }
        }
        return -1;
    }
};
