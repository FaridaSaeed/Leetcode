class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), c = 0, ans = 0;
        while(r<n)
        {
            if(nums[r])
                r++;
            else if(c<k){
                c++;
                r++;
            }
            else
            {
                if(!nums[l])c--;
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
    
};