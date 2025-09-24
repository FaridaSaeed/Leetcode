class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<char>st;
        for(auto i:s)
        {
            if(i==']')
            {
                string tmp;
                while(st.top()!='[')
                {
                    tmp+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(tmp.begin(),tmp.end());
                string x;
                while(!st.empty()&& st.top()-'0'>=0 && st.top()-'0'<=9)
                {
                    x+=st.top();
                    st.pop();
                }
                reverse(x.begin(),x.end());
                cout<<x<<' ';
                int c = stoi(x);
                x.clear();
                while(c--)x+=tmp;
                for(auto j:x)
                    st.push(j);
            }
            else st.push(i);
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};