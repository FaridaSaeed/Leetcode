class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i && nums[i]==nums[i-1])continue;
            int j = i+1,k=n-1;
            while(j<k)
            {
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0)k--;
                else if(sum<0)j++;
                else {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};