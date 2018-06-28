class Solution {
public:
    int reverse(int num) {
        int reversedNum = 0;
        while (num) {
            if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && (num % 10) > 7)) {
                return 0;
            }
            if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && (num % 10) < -8)) {
                return 0;
            }
            reversedNum = reversedNum * 10 + (num % 10);
            num /= 10;
        }
        return reversedNum;
    }
};
