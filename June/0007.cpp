class Solution {
public:
    int reverse(int num) {
        if (num == INT_MIN) {
            return 0;
        }
        int sign = (num < 0) ? -1 : 1;
        int reversedNum = 0;
        num = abs(num);
        while (num) {
            int numLimit = INT_MAX / 10;
            if (reversedNum < numLimit || (reversedNum == numLimit && (num % 10) <= INT_MAX - numLimit * 10)) {
                reversedNum = reversedNum * 10 + (num % 10);
            } else {
                return 0;
            }
            num /= 10;
        }
        return sign * reversedNum;
    }
};
