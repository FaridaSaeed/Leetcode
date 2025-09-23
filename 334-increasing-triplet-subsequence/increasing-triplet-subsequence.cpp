class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn = INT_MAX, secmn = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mn)
            {
                mn  = nums[i];
                
            }
            else if(nums[i]>mn && nums[i]<secmn)
            {
                secmn = nums[i];
            }
            else if(nums[i]>secmn)return true;
        }
        return false;
    }
};