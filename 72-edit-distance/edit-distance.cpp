const int N = 505;
int mem[N][N];
int n,m;
string s1,s2;
int dp(int i,int j)
{
    if (i == n) return m - j; 
    if (j == m) return n - i;
    int &ret = mem[i][j];
    if(~ret)return ret;
    ret = (s1[i]!=s2[j])+dp(i+1,j+1);
    ret = min(ret,1+dp(i+1,j));
    ret = min(ret,1+dp(i,j+1));
    
    return ret;
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        s1 = word1, s2 = word2;
        n = word1.size();
        m = word2.size();
        memset(mem,-1,sizeof mem);
        return dp(0,0);
    }
};