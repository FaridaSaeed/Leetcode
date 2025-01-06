const int N = 1e3+5;
class Solution {
public:
    int mem[N][N];
    int n,m;
    string t1,t2;
    int dp(int i,int j)
    {
        if(i>=n || j>=m)return 0;
        int &ret = mem[i][j];
        if(~ret)return ret;
        ret = 0;
        if(t1[i]==t2[j])
            ret = 1+dp(i+1,j+1);
        else 
            ret = max({ret,dp(i+1,j),dp(i,j+1)});
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1;
        t2 = text2;
        n  = text1.size();
        m = text2.size();
        memset(mem,-1,sizeof mem);
        return dp(0,0);
    }
};