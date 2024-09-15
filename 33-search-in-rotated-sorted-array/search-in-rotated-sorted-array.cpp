class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            //if left is sorted
            if(nums[mid]>=nums[low]){
                if(nums[mid]>=target&&nums[low]<=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //if right is sorted
            else{
                if(nums[mid]<=target&&nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            if(target==nums[mid]){
                return mid;
            }

        }
        return -1;
    }
};