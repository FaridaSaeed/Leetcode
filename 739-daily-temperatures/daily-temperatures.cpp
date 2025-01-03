class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                int x = st.top();
                st.pop();
                res[x] = i-x; 
            }
            st.push(i);
        }
        return res;

        return res;        
    }
};