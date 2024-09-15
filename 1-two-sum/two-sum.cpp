class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp,mp2;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]] = i+1;
            mp2[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[target-nums[i]])
            {
                if(target-nums[i] == nums[i] && mp2[nums[i]]==1)continue;
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]-1);
                return ans;
            }
        }
        return ans;
    }
};