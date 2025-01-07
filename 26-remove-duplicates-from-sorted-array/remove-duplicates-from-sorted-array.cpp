class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0,ans = 0;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            if(!mp[i]){
                nums[ind] = i;
                mp[i]++;
                ind++;
            }
        }
        return ind;
    }
};