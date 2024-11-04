const int N = 205;
int dx[] = {0,1};
int dy[] = {1,0};
class Solution {
public:
    int mem[N][N];
    int n,m;
    vector<vector<int>> g;
    int dp(int i,int j)
    {
        int &ret = mem[i][j];
        if(~ret)return ret;
        ret = g[i][j];
        int ans = 1e9;
        for(int l=0;l<2;l++)
        {
            if(i+dx[l]<n && j+dy[l]<m)
                ans = min(ans,dp(i+dx[l],j+dy[l]));
        }
        if(ans==1e9) ans = 0;
        ret+=ans;
        return ret;
    }
    int minPathSum(vector<vector<int>>& grid) {
        g = grid;
        memset(mem,-1,sizeof mem);
        n = grid.size();
        m = grid[0].size();
        return dp(0,0);
    }
};