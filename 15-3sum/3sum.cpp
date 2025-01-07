class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0,n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int x = nums[i]+nums[j];
                int ind = lower_bound(nums.begin()+j+1,nums.end(),-1*x)-nums.begin();
                if(ind<n && nums[ind]+x==0)
                {
                    vector<int>res = {nums[i],nums[j],nums[ind]};
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};