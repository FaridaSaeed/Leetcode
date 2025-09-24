
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int>mp;
        map<int,int> query;
        for(auto i:nums){
            mp[i]++;
            query[i]+= 0;
            query[i+k+1]--;
            if(i-k<0)query[0]++;
            else query[i-k]++;
        }
        int ans = 0;
        int sum = 0;
        for(auto i:query)
        {
            sum+=i.second;
            ans = max(ans,mp[i.first] + min(sum-mp[i.first],numOperations));
        }
        return ans;

    }

};
