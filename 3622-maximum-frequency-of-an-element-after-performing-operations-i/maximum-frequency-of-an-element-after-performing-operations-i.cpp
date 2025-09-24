
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int>mp;
        int N =0;
        for(auto i:nums)N = max(N,i);
        N*=3;
        N+=k;
        vector<int>v(N);
        for(auto i:nums){
            mp[i]++;
            v[i+k+1]--;
            if(i-k<0)v[0]++;
            else v[i-k]++;
        }
        int ans = 0;
        for(int i=1;i<N;i++)
        {
            v[i]+=v[i-1];
            ans = max(ans,mp[i] + min(v[i]-mp[i],numOperations));
        }
        return ans;

    }

};