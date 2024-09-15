const int N = 1e4+5,M = 1e3+5;
int mem[N];
int n;
int dp(int ind,int jmp,vector<int>& nums)
{
    if(ind>=n-1)return 0;
    int &ret = mem[ind];
    if(~ret)return ret;
    ret = 1e9;
    for(int i=1;i<=jmp;i++)
        if(ind+i<n)
            ret = min(ret,1+dp(ind+i,nums[ind+i],nums));
    return ret;
}
class Solution {
public:
    int jump(vector<int>& nums) {
        memset(mem,-1,sizeof mem);
        n = nums.size();   
        return dp(0,nums[0],nums);
    }
};