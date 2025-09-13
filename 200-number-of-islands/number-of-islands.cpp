int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    int n,m;
    vector<vector<bool>>vis;
    bool valid(int x,int y,vector<vector<char>>& grid)
    {
        return(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'&& !vis[x][y]);
    }
    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        vis[i][j] = true;
        for(int x = 0 ;x<4;x++)
            if(valid(i+dx[x],j+dy[x],grid))
                dfs(i+dx[x],j+dy[x],grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n);
        for(auto &i:vis)i.resize(m);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};