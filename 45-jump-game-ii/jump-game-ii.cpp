const int N = 1e4+2;
class Solution {
public:
    int mem[N];
    int n;
    vector<int>num;
    int dp(int i)
    {
        if(i>=n-1)return 0;
        int &ret = mem[i];
        if(~ret)return ret;
        ret = 1e5;
        for(int j=1;j<=num[i];j++)
        {
            ret = min(ret,1+dp(i+j));
        }
        return ret;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        num = nums;
        memset(mem,-1,sizeof mem);
        return dp(0);
    }
};