const int N = 105;
class Solution {
public:
    int mem[N];
    int n;
    int dp(int i,vector<int>& nums)
    {
        if(i>=n)return 0;
        int &ret = mem[i];
        if(~ret)return ret;
        ret = max(nums[i]+dp(i+2,nums),dp(i+1,nums));
        return ret;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(mem,-1,sizeof mem);
        return dp(0,nums);   
    }
};