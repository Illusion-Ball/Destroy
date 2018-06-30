class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0 || (num % 10 == 0 && num != 0)) {
            return false;
        }
        int reversedNum = 0;
        while (num > reversedNum) {
            reversedNum = reversedNum * 10 + (num % 10);
            num /= 10;
        }
        return reversedNum == num || (reversedNum / 10) == num;
    }
};
