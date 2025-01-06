const int N = 5e4+1;
class Solution {
public:
    int mem[N][2];
    vector<int>p;
    int f;
    int n;
    int dp(int i,int c)
    {
        if(i>=n)return 0;
        int &ret = mem[i][c];
        if(~ret)return ret;
        ret = 0;
        if(c==1)ret = max(dp(i+1,1),p[i]-f+dp(i+1,0));
        else
            ret = max(dp(i+1,0),-p[i]+dp(i+1,1));
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        f = fee;
        p = prices;
        n = prices.size();
        memset(mem,-1,sizeof mem);
        return dp(0,0);
    }
};