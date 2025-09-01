const int N = 1e4+5;
class Solution {
public:
    int mem[N];
    int dp(int ind,int n,vector<int>&nums)
    {
        if(ind>=n-1)return 0;
        int &ret = mem[ind];
        if(~ret)return ret;
        ret = 1e5;
        for(int i=1;i<=nums[ind];i++)
            ret = min(ret,1+dp(i+ind,n,nums));
        return ret;
    }
    int jump(vector<int>& nums) {
        memset(mem,-1,sizeof mem);
        int n = nums.size();
        return dp(0,n,nums);
    }
};