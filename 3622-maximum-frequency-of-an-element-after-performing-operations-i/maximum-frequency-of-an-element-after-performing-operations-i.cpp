const int N = 3*1e5;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int>freq(N);
        int mx = 0;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
            if(i-k<0)freq[0]++;
            else freq[i-k]++;
            freq[i+k+1]--;
            mx = max(mx,i+k);
        }
        int ans = 0;
        for(int i=1;i<=mx;i++){
            freq[i]+=freq[i-1];
            ans = max(ans,mp[i]+min(freq[i]-mp[i],numOperations));
        }
        return ans;
    }
};