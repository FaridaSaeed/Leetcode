class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            int x = temperatures[i];
            if(st.empty() || x<temperatures[st.top()])st.push(i);
            else 
            {
                while(!st.empty() && x>temperatures[st.top()])
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};