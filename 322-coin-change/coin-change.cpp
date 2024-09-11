const int N = 15,M = 1e5;
int mem[N][M];
int n;
class Solution {
public:
    int dp(int ind,int amount,vector<int>& coins)
    {
        if(amount==0)
            return 0;
        if(ind>=n)return 1e9;
        int &ret = mem[ind][amount];
        if(~ret)return ret;
        ret = 1e9;
        ret = dp(ind+1,amount,coins);
        if(amount>=coins[ind])ret = min(ret,1+dp(ind,amount-coins[ind],coins));
        return ret;

    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(mem,-1,sizeof mem);
        int ans = dp(0,amount,coins);
        return (ans>=1e9?-1:ans);
    }
};