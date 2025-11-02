class Solution {
public:
    int dp(int i,int j,string &s,vector<vector<int>>&mem)
    {
        if(i>=j)return 0;
        int &ret = mem[i][j];
        if(~ret)return ret;
        if(s[i]==s[j])ret = dp(i+1,j-1,s,mem);
        else ret = 1+min(dp(i+1,j,s,mem),dp(i,j-1,s,mem));
        return ret;
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>mem(n,vector<int>(n,-1));
        return dp(0,n-1,s,mem);
    }
};