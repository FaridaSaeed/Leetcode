class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre = nums;
        int n = nums.size();
        for(int i=1;i<n;i++)
            pre[i]*=pre[i-1];
        int r = 1;
        for(int i=n-1;i>0;i--)
        {
            int x = r*pre[i-1];
            r*=nums[i];
            nums[i] = x;
        }
        nums[0] = r;
        return nums;
    }
};