class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int>fre(2*1e5);
        unordered_map<int,int>mp;
        int mx = 0;
        int mxele = 0;
        for(auto i:nums){
            if(i-k<0)fre[0]++;
            else 
                fre[i-k]++;
            fre[i+k+1]--;
            mp[i]++;
            mxele = max(mxele,i+k+1);
            }

        for(int i=1;i<=mxele;i++)
        {
            fre[i]+=fre[i-1];
            mx = max(mx,min(fre[i],mp[i]+numOperations));
        }
        return mx;
    }
};