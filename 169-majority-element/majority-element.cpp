class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx = 0,el;
        for(auto i:nums)
        {
            mp[i]++;
            if(mp[i]>mx)
            {
                mx = mp[i];
                el = i;
            }
        }
        return el;
    }
};