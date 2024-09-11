class Solution {
public:
    vector<int>dx;
    vector<int>dy;
    int n,m,sz;
    string s;
    vector<vector<char>>brd;
    vector<vector<int>>vis;
    Solution()
    {
        dx = {0,0,1,-1};
        dy = {1,-1,0,0};
    }
    bool valid(int x,int y,int ind)
    {
        if(x>=0 && x<n && y>=0 && y<m && ind<sz && brd[x][y]==s[ind] && !vis[x][y])return true;
        return false;
    }
    bool dfs(int ind,int i,int j)
    {
        if(ind==sz-1){
            return true;

        }
        vis[i][j] = true;
        bool ret = false;
        for(int k = 0;k<4;k++)
        {
            int xx = i+dx[k];
            int yy = j+dy[k];
            if(valid(xx,yy,ind+1)){
                ret = max(ret,dfs(ind+1,xx,yy));
                vis[xx][yy] = false;
            }
        }
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        sz = word.size();
        s = word;
        brd = board;
        vis.resize(n);
        for(auto &i:vis)i.resize(m);
        
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(auto &i:vis)for(auto &j:i)j = 0;
                if(board[i][j]==word[0])ans = max(ans,dfs(0,i,j));
            }
        }
        return ans;
    }
};