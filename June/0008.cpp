class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int sign = 1;
        int i = 0;
        while (i < len && str[i] == ' ') {
            i++;
        }
        if (i < len && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') {
                sign = -1;
            }
            i++;
        }
        int num = 0;
        bool numExists = (i < len && str[i] >= '0' && str[i] <= '9');
        bool overflow = false;
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            if (num < INT_MAX / 10 || (num == INT_MAX / 10 && str[i] <= '7')) {
                num = num * 10 + (str[i] - '0');
            } else {
                overflow = true;
                break;
            }
            i++;
        }
        if (! numExists) {
            return 0;
        }
        if (overflow) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        return sign * num;
    }
};
