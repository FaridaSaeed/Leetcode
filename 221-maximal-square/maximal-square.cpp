const int N = 301;
class Solution {
public:
    int mem[N][N];
    int n,m;
    vector<vector<char>> mat;
    int ans = 0;
    int dp(int i,int j)
    {
        if(i>=n || j>=m)return 0;
        int &ret = mem[i][j];
        if(~ret)return ret;
        if(mat[i][j]=='1')
        {
            int right = dp(i,j+1);
            int down = dp(i+1,j);
            int diag = dp(i+1,j+1);
            ret = 1+min({right,down,diag});
            ans = max(ans,ret);
            return ret;
        }
        return 0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        mat = matrix;
        n = matrix.size();
        m = matrix[0].size();
        memset(mem,-1,sizeof mem);
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j]=='1' && mem[i][j]==-1)dp(i,j);
            }
        }

        return ans*ans;
    }
};