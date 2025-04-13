class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i && nums[i]==nums[i-1])continue;
            for(int j = i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k = j+1 , m = n-1;
                while(k<m){
                    long long total = nums[i]+nums[j];
                    total +=nums[k]+nums[m];
                    if(total>target)m--;
                    else if(total<target)k++;
                    else
                    {
                        vector<int>res = {nums[i],nums[j],nums[k],nums[m]};
                        ans.push_back(res);
                        k++;
                        while(k<m && nums[k]==nums[k-1])k++;
                    }
                }

            }
        }
        return ans;
    }
};