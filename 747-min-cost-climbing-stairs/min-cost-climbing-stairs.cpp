const int N = 1e3+5;
class Solution {
public:
    int mem[N];
    int n;
    vector<int>cst;
    int dp(int ind)
    {
        if(ind>=n)return 0;
        int &ret = mem[ind];
        if(~ret)return ret;
        ret = 1e9;
        ret = min({ret,cst[ind]+dp(ind+1),cst[ind]+dp(ind+2)});
        return ret;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(mem,-1,sizeof mem);
        n = cost.size();
        cst = cost;
        return min(dp(0),dp(1));   
    }
};