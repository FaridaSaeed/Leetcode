const int N = 105;
int dx[] = {0,1};
int dy[] = {1,0};
class Solution {
public:
    int mem[N][N];
    int n,m;
    vector<vector<int>> g;
    bool valid(int x,int y)
    {
        return (x>=0 && x<n && y>=0 && y<m && !g[x][y]);
    }
    int dp(int i,int j)
    {
        if(i>=n || j>=m || g[i][j]==1)return 0;
        if(i==n-1 && j==m-1)return 1;
        int &ret = mem[i][j];
        if(~ret)return ret;
        ret = 0;
        for(int l=0;l<2;l++)
        {
            if(valid(i+dx[l],j+dy[l]))
                ret+=dp(i+dx[l],j+dy[l]);
        }
        return ret;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        g = obstacleGrid;
        n = g.size();
        m = g[0].size();
        memset(mem,-1,sizeof mem);
        return dp(0,0);
    }
};