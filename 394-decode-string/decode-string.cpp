class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i==']')
            {
                string x;
                while(!st.empty() && st.top()!='[')
                {
                    x+=st.top();
                    st.pop();
                }
                if(st.top()=='[')
                {
                    st.pop();
                    reverse(x.begin(),x.end());
                    string num;
                    while(!st.empty() && st.top()!='[' && !(st.top()>='a' && st.top()<='z'))
                    {
                        num+=st.top();
                        st.pop();
                    }
                    reverse(num.begin(),num.end());
                    int n = 0;
                    if(num.size())
                        n = stoi(num);
                    string a;
                    while(n--)a+=x;
                    cout<<a<<' ';
                    for(auto f:a)
                        st.push(f);
                }
            }
            else st.push(i);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};