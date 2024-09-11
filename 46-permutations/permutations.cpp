class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>& nums,int ind)
    {
        int n = nums.size();
        if(ind>=n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            swap(nums[ind],nums[i]);
            backtrack(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0);
        return ans;   
    }
};