class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        string ans;
        for(int i=0;i<min(n,m);i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        if(n>m)
            for(int i=m;i<n;i++)ans+=word1[i];
        else
            for(int i=n;i<m;i++)ans+=word2[i];
        return ans;
    }
};