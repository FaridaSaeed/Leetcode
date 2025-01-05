class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n = height.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[i]>=height[st.top()])
            {
                int ind = st.top();
                st.pop();
                if(!st.empty())
                {
                    ans+=(i-st.top()-1)*(min(height[st.top()],height[i])-height[ind]);
                }
            }
            st.push(i);
        }
        return ans;
    }
};