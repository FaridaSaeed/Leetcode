class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end()){
                if(i-mp[nums[i]].second<=k)return true;
                mp[nums[i]].first = mp[nums[i]].second;
                mp[nums[i]].second = i;
            }
            else {
                mp[nums[i]].first = i;
                mp[nums[i]].second = i;
            }
        }
        //for(auto i:mp)if(i.second.second-i.second.first<=k && i.second.second-i.second.first>0)return true;
        return false;
    }
};