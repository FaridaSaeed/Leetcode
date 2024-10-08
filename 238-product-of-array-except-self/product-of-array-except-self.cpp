class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int r = 1,n = nums.size();
        vector<int>pre = nums;
        for(int i=1;i<n;i++){
            pre[i]*=pre[i-1];
        }
        for(int i=n-1;i>0;i--)
        {
            pre[i] = pre[i-1]*r;
            r*=nums[i];
        }
        pre[0] = r;
        return pre;
    }
};