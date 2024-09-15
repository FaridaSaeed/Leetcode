class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i=='[')st.push(i);
            else if(!st.empty())st.pop();
        }
        return ceil(1.0*st.size()/2);
    }
};