class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i=='(' || i=='{' || i=='[')st.push(i);
            else if(i==')')
            {
                if(st.empty() || st.top()!='(')return false;
                else st.pop();
            }
            else if(i==']')
            {
                if(st.empty() || st.top()!='[')return false;
                else st.pop();
            }
            else if(i=='}')
            {
                if(st.empty() || st.top()!='{')return false;
                else st.pop();
            }
        }
        if(!st.empty())return false;
        return true;
    }
};