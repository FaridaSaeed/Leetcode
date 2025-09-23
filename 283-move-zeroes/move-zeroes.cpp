class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(!nums[i])
            {
                int j = i;
                while(j+1<n && nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    j++;
                }
            }
        }
    }
};