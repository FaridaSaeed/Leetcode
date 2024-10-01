class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        vector<int>v;
        for(auto i:mp)v.push_back(i.first);
        int l = 0 ,r = 1,n = v.size();
        if(n==0)return 0;
        int mx = 1;
        while(r<n)
        {
            if(v[r]-v[r-1]==1){
                r++;
                mx = max(mx,r-l);
            }
            else l=r++;
        }
        return mx;

    }
};