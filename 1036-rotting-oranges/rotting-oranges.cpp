class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    bool valid(int x,int y)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        bool found = false;
        for(auto i:grid)
            for(auto j:i)
                if(j==1)
                    found = true;
        if(!found)return 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>lvl(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(grid[i][j]==2){
                    q.push({i,j});
                    lvl[i][j] = 0;
                }
        }
        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int first = p.first+dx[i] , second = p.second+dy[i];
                if(valid(first,second) && lvl[first][second]==-1 && grid[first][second]==1)
                {
                    lvl[first][second] = lvl[p.first][p.second]+1;
                    q.push({first,second});
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && lvl[i][j]==-1)
                    return -1;
                ans = max(ans,lvl[i][j]);
            }
                
        return ans;
    }

};