class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n = height.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[st.top()]<=height[i])
            {
                int mid = st.top();
                st.pop();
                if(!st.empty())
                {
                    int l = st.top();
                    ans+=(i-l-1)*(min(height[i],height[l])-height[mid]);
                }
            }
            st.push(i);
        }
        return ans;
    }
};