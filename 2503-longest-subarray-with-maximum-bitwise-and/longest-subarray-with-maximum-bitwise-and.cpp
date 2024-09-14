class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0;
        for(auto i:nums)
            mx = max(mx,i);
        int ans = 1;
        for(int i=0;i<nums.size();i++)
        {
            int x = 0;
            while(i<nums.size()&&nums[i]==mx){
                x++;
                i++;
            }
            ans = max(ans,x);
        }
        return ans;
    }
};