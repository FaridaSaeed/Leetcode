class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int number = 0;
        int sign = 1;

        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '-' || s[i] == '+') {
                result += sign * number; 
                number = 0;
                sign = (s[i] == '-') ? -1 : 1;
            }
            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            }
            else if (s[i] == ')') {
                result += sign * number; 
                number = 0; 

                int prevSign = st.top();
                st.pop();
                int prevResult = st.top();
                st.pop();
                result = prevResult + prevSign * result;
            }
        }
        if (number != 0) result += sign * number;
        return result;
    }
};