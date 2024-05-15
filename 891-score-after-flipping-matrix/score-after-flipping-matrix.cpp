class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;j++)
                {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            int ons = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                    ons++;
            }
            if(ons<(n-ons))
            {
                for(int j=0;j<n;j++)
                {
                    grid[j][i]=!grid[j][i];
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int x = 0;
            for(int j=0;j<m;j++)
            {
                x+=grid[i][j]*pow(2,m-j-1);
            }
            res+=x;
        }
        return res;
    }
};