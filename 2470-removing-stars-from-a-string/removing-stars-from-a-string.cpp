class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto i:s)
            if(i!='*')st.push(i);
            else st.pop();
        s.clear();
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};