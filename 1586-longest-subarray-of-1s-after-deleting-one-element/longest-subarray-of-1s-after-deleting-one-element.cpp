class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0,r = 0,n = nums.size(),c = 0,mx = 0;
        while(r<n)
        {
            if(nums[r]==0)c++;
            while(c>1)
            {
                if(nums[l]==0)c--;
                l++;
            }
            mx = max(mx,r-l);
            r++;
        }
        return mx;
    }
};