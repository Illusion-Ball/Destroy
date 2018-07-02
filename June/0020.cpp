class Solution {
    bool isOpeningBracket(char ch) {
        return (ch == '(' || ch == '{' || ch == '[');
    }
    
    char getOpeningBracket(char ch) {
        switch(ch) {
            case ')' : return '(';
            case '}' : return '{';
            case ']' : return '[';
        }
    }
    
public:
    bool isValid(string s) {
        stack<char> parantheses;
        for(char ch : s) {
            if (isOpeningBracket(ch)) {
                parantheses.push(ch);
            } else if (parantheses.empty() || (parantheses.top() != getOpeningBracket(ch))) {
                return false;
            } else {
                parantheses.pop();
            }
        }
        return parantheses.empty();
    }
};
