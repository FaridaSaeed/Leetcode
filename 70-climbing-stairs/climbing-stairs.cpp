const int N = 50;
class Solution {
public:
    int mem[N];
    int dp(int n)
    {
        if(n==0)return 1;
        int &ret = mem[n];
        if(~ret)return ret;
        if(n>1)
            ret = dp(n-1)+dp(n-2);
        else ret = dp(n-1);
        return ret;
    }
    int climbStairs(int n) {
        memset(mem,-1,sizeof mem);
        return dp(n);
    }
};