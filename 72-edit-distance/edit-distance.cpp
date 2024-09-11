const int N = 505;
int mem[N][N];
string s1,s2;
int dp(int n, int m) {
    if (!n || !m) return n + m;
    int &ret = mem[n][m];
    if (~ret) return ret;
    ret = (s1[n - 1] != s2[m - 1]) + dp(n - 1, m - 1);
    ret = min(ret, 1 + dp(n - 1, m));
    ret = min(ret, 1 + dp(n, m - 1));
    return ret;
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        s1 = word1, s2 = word2;
        int n = word1.size();
        int m = word2.size();
        memset(mem,-1,sizeof mem);
        return dp(n,m);
    }
};