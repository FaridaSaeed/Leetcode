class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0,r = 0,n = nums.length,ans = 0;
        int x = 0;
        while(r<n)
        {
            if(nums[r]==0)x++;
            while(x>k)
            {
                if(nums[l]==0) x--;
                l++;
            }
            ans = Math.max(ans,r-l+1);
            r++;
        }
        return ans;
    }
}