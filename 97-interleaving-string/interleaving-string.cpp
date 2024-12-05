const int N = 205;
int dp[N][N][N];
class Solution {
public:
    int n,m,h;
    string st1,st2,st3;
    bool solve(int i, int j, int k) {
        if (i == n && j == m && k == h) return true;
        int &ret = dp[i][j][k];
        if (~ret) return ret;
        bool result = false;
        if (i < n && st1[i] == st3[k]) {
            result = result || solve(i + 1, j, k + 1);
        }

        if (j < m && st2[j] == st3[k]) {
            result = result || solve(i, j + 1, k + 1);
        }

        return ret = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        n = s1.size();
        m = s2.size();
        h = s3.size();
        st1 = s1;
        st2 = s2;
        st3 = s3;
        if (n+m != h) {
            return false;
        }
        return solve(0, 0, 0);
    }
};