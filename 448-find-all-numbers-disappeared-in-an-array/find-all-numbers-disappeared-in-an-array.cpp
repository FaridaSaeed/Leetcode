class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto i:nums){
            int indx = abs(i)-1;
            nums[indx] = -1*abs(nums[indx]);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)if(nums[i]>0)ans.push_back(i+1);
        return ans;
    }
};