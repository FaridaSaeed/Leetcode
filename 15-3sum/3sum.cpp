class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int target = 0,n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i && nums[i]==nums[i-1])continue;
            int j = i+1,k = n-1;
            while(j<k)
            {
               int total = nums[i]+nums[j]+nums[k];
               if(total>0)k--;
               else if(total<0)j++;
               else 
               {
                    vector<int>res = {nums[i],nums[j],nums[k]};
                    ans.push_back(res);
                    j++;
                    while(nums[j]==nums[j-1] && j<k)j++;
               }

            }
        }
        return ans;
    }
};