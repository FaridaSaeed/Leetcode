class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int c = 0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[k-nums[i]]>0)
            {
                if((nums[i]==(k-nums[i]) && mp[nums[i]]<=1))continue;
                mp[nums[i]]--;
                mp[k-nums[i]]--;
                c++;
            }

        }
        return c;
    }
};