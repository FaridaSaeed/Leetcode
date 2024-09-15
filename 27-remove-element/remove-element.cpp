class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ind = 0;;
        for(auto &i:nums){
            if(i!=val){
                nums[ind] = i;
                ind++;
            }
        }
        return ind;
    }
};