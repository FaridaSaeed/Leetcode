const int N = 205;
class Solution {
public:
    int mem[N][N];
    int n;
    vector<vector<int>> tri;
    int dp(int i,int j)
    {
        if(i>=n || j>=n)return 0;
        int &ret = mem[i][j];
        if(~ret)return ret;
        ret = 0;
        ret += tri[i][j] + min(dp(i+1,j),dp(i+1,j+1));
        return ret;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        tri = triangle;
        memset(mem,-1,sizeof mem);
        n = triangle.size();
        return dp(0,0);
    }
};