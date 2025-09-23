class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int right = 0;
        for(int i=0;i<n;i++)
            if(nums[i])
                nums[right++] = nums[i];
        for(int i=right;i<n;i++)nums[i] = 0;
    }
};