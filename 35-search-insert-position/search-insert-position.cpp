class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1,r = n,mid;
        while(l+1<r)
        {
            mid = (r+l)/2;
            if(nums[mid]<target) l = mid;
            else if(nums[mid]>target)r = mid;
            else return mid;
        }
        return r;
    }
};