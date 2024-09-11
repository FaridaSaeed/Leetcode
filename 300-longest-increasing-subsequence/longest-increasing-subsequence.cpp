const int N = 1e4;
int mem[N][N];
int n;
vector<int>num;
int dp(int ind,int lst)
{
    if(ind>=n)return 0;
    int &ret = mem[ind][lst+1];
    if(~ret)return ret;
    ret = 0;
    if(lst==-1 || num[ind]>num[lst]) ret = 1+dp(ind+1,ind);
    ret = max(ret,dp(ind+1,lst));
    return ret;
}
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        memset(mem,-1,sizeof mem);
        num = nums;
        n = nums.size();
        return dp(0,-1);
    }
};