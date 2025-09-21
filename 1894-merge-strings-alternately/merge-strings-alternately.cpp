class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int sz1 = word1.size() , sz2 = word2.size();
        int mnsz = min(sz1,sz2);
        string ans;
        for(int i=0;i<mnsz;i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        for(int i = mnsz; i<sz1;i++)
            ans+=word1[i];
        for(int i = mnsz; i<sz2;i++)
            ans+=word2[i];
        return ans;
    }
};