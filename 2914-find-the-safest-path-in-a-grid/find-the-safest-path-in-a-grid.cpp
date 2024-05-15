const int N = 405;
class Solution {
public:
    int n;
    bool vis[N][N];
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    vector<pair<int,int>>ons;
    int ans;
    bool valid(int x,int y)
    {
        return(x>=0 && x<n && y>=0 && y<n);
    }
    Solution()
    {
        memset(vis,0,sizeof vis);
        ans = 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid .size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1)return 0;
        vector<vector<int>>vmn(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    vmn[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first,y = p.second;
            int sm = vmn[x][y];
            for(int l=0;l<4;l++)
            {
                int newX = x + xx[l];
                int newY = y + yy[l];
                if(valid(newX,newY) && vmn[newX][newY]==-1)
                {
                    vmn[newX][newY] = sm+1;
                    q.push({newX,newY});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({vmn[0][0], {0,0}});

        while(!pq.empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if(temp.first == n - 1 && temp.second == n - 1) return safe;
            vis[temp.first][temp.second] = true;

            for(int i = 0; i < 4; i++) {
                int newX = temp.first + xx[i];
                int newY = temp.second + yy[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]){
                    int s = min(safe, vmn[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }
        return -1;

    }
};