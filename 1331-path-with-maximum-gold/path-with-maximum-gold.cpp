const int N = 50;
int n,m;
bool vis[N][N];
int xx[]={-1,1,0,0};
int yy[]={0,0,-1,1};
vector<vector<int>>v;
bool valid(int x,int y)
{
    return(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && (v[x][y]!=0));
}
int mxx = 0;
void dfs(int i,int j, int sm)
{
    sm+=v[i][j];
    mxx = max(mxx,sm);
    vis[i][j]=true;
    for(int l=0;l<4;l++)
        if(valid(i+xx[l],j+yy[l])) {
            dfs(i+xx[l],j+yy[l],sm);
            vis[i+xx[l]][j+yy[l]] = false;
        }
}
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        v = grid;
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]){
                    memset(vis,0,sizeof vis);
                    mxx = 0;
                    dfs(i,j,0);
                    mx  = max(mx,mxx);
                }
            }
        }
        return mx;
    }
};