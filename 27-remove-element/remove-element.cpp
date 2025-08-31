class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = nums.size();
        for(auto &i:nums)if(i==val){
            i = 100;
            c--;
        }
        sort(nums.begin(),nums.end());
        return c;
    }
};