const int N = 1e5+5;
int mem[N][2][3];
int n;
int dp(int i,int x,int tran,vector<int>& prices)
{
    if(i>=n || tran>=2)return 0;
    int &ret = mem[i][x][tran];
    if(~ret)return ret;
    ret = dp(i+1,x,tran,prices);
    if(x==1)
        ret = max(ret, dp(i+1,0,tran,prices)-prices[i]);
    else ret = max(ret, prices[i]+dp(i+1,1,tran+1,prices));
    return ret;
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memset(mem,-1,sizeof mem);
        n = prices.size();
        return dp(0,1,0,prices);
    }
};