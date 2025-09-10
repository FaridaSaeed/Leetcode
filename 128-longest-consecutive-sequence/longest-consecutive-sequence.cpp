class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mx = 0;
        for(auto i:st)
        {
            if(st.find(i-1)==st.end())
            {
                int len = 1;
                while(st.find(i+len)!=st.end())
                {
                    len++;
                }
                mx = max(mx,len);
            }
        }
        return mx;
    }

};