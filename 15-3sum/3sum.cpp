class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i && nums[i]==nums[i-1])continue;
            int j = i+1,k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0)k--;
                else if(sum<0)j++;
                else {
                    vector<int>res = {nums[i],nums[j],nums[k]};
                    ans.push_back(res);
                    j++;
                    while(j<k && nums[j]==nums[j-1])j++;
                }
            }
        }
        return ans;
    }
};