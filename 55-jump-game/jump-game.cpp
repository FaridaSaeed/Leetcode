class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind = 0,n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(i<=ind && i+nums[i]>=ind)ind = i+nums[i];
        }
        return ind>=n-1;
    }
};