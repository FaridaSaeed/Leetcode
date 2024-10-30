const int N = 205;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    bool vis[N][N];
    int n,m;
    bool isValid(int i,int j,vector<vector<char>>& board)
    {
        return(i>=0 && i<=n-1 && j>=0 && j<=m-1 && board[i][j]=='O' && !vis[i][j]);
    }
    bool valid(int i,int j,vector<vector<char>>& board)
    {
        return((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O' && !vis[i][j]);
    }
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        vis[i][j] = true;
        for(int x = 0;x<4;x++)
        {
            if(isValid(i+dx[x],j+dy[x],board))
                dfs(i+dx[x],j+dy[x],board);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(valid(i,j,board))dfs(i,j,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')board[i][j] = 'X';
            }
        }
    }

};