class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(auto i:s)st.push(i);
        int indx = 0;
        while(!st.empty()){
            s[indx] = st.top();
            indx++;
            st.pop();
        }
    }
};