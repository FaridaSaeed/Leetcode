class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        int k = 0;
        for(auto &i:nums)
        {
            mp[i]++;
            if(mp[i]>2)i = 100000;
            else k++;
        }
        sort(nums.begin(),nums.end());
        return k;

    }
};