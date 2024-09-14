class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx = 0,ans = 0;
        map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
            if(mp[i]>mx)
            {
                mx = mp[i];
                ans = i;
            }
        }
        return ans;
    }
};