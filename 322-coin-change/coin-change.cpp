const int N = 15,M = 1e5;
int mem[N][M];
int n;
class Solution {
public:
    int dp(int ind,int amount,vector<int>& coins)
    {
        if(amount==0)
            return 0;
        int &ret = mem[ind][amount];
        if(~ret)return ret;
        ret = 1e9;
        for(int i=0;i<n;i++)
        {
            if(amount>=coins[ind])ret = min(ret,1+dp(ind,amount-coins[ind],coins));
            if(i+1<n)
                ret = min(ret,dp(i+1,amount,coins));
        }
        return ret;

    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(mem,-1,sizeof mem);
        int ans = dp(0,amount,coins);
        return (ans>=1e9?-1:ans);
    }
};