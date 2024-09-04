const int N = 105;
class Solution {
public:
    int mem[N];
    int n;
    vector<int>num;
    int dp(int i)
    {
        if(i>=n)return 0;
        int &ret = mem[i];
        if(~ret)return ret;
        ret = num[i] + dp(i+2);
        ret = max(ret,dp(i+1));
        return ret;
    }
    int rob(vector<int>& nums) {
        num = nums;
        n = nums.size();
        memset(mem,-1,sizeof mem);
        return dp(0);
    }
};