class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = -1,r = nums.size(),mid;
        while(l<r-1)
        {
            mid = (l+r)/2;
            if(target==nums[mid])return mid;
            if(target>nums[mid])l = mid;
            else r = mid;
        }
        return -1;
    }
};