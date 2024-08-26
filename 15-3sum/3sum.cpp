class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int sum = 0;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int x = 0-(nums[i]+nums[j]);
                if(x>=nums[j])
                {
                    if(((x == nums[i] && x==nums[j]) && mp[x]>2) || (x != nums[i] && x!=nums[j] && mp[x]))
                    {
                        vector<int>v = {nums[i],nums[j],x};
                        st.insert(v);
                    }
                    else if(((x != nums[i] && x==nums[j])||(x == nums[i] && x!=nums[j])) && mp[x]>1)
                    {
                        vector<int>v = {nums[i],nums[j],x};
                        st.insert(v);
                    }
                }
            }
        } 
        vector<vector<int>>v;
        v.assign(st.begin(),st.end());  
        return v;  
    }
};