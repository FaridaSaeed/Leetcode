class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        bool rev = false;
        vector<int>cells(n*n+1);
        int l = 1;
        for(int i = n-1;i>=0;i--)
        {
            if(rev)
            {
                for(int j = n-1;j>=0;j--)
                {
                    cells[l] = (board[i][j]==-1?l:board[i][j]);
                    l++;
                }
            }
            else
            {
                for(int j = 0;j<n;j++)
                {
                    cells[l] = (board[i][j]==-1?l:board[i][j]);
                    l++;
                }
            }
            rev = !rev;
        }
        queue<int>q;
        vector<int>lvl(n*n+1,-1);
        q.push(1);
        lvl[1] = 0;
        for(auto i:cells)cout<<i<<' ';
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            int next = curr+1;
            for(;next<=min(curr+6,n*n);next++)
            {
                
                if(lvl[cells[next]]==-1 || lvl[curr]+1<lvl[cells[next]])
                {
                    lvl[cells[next]] = lvl[curr]+1;
                    q.push(cells[next]); 
                }
            }
        }
        cout<<'\n';
        for(auto i:lvl)cout<<i<<' ';
        return lvl[n*n];
    }
};