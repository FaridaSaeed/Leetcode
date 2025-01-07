const int N = 3*1e5;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int>mp,freq;
        for(auto i:nums)
        {
            mp[i]++;
            if(i-k<0)freq[0]++;
            else freq[i-k]++;
            freq[i+k+1]--;
            freq[i] += 0;
        }
        int ans = 0;
        int lst = 0;
        for(auto i:freq)
        {
            i.second+=lst;
            ans = max(ans,min(i.second,mp[i.first]+numOperations));
            lst = i.second;
        }
        return ans;
    }
};