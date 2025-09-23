class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        int ans = 0;
        for(auto i:nums)
        {
            if(mp[k-i]){
                if(i==k-i)ans+=mp[i]/2;
                else
                    ans+=min(mp[k-i],mp[i]);
                mp[i] = mp[k-i] = 0;
            }
        }
        return ans;
    }
};