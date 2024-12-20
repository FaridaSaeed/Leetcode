class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 ,r = 0,n = nums.size(),c = 0,mx = 0;
        while(r<n)
        {
            if(nums[r]==0) c++;
            while(c>k)
            {
                if(nums[l]==0)c--;
                l++;
            }
            mx = max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};