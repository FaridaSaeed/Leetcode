class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>m1(26);
        vector<int>m2(26);
        for(auto i:word1)
            m1[i-'a']++;
        for(auto i:word2)m2[i-'a']++;
        for(char i = 0;i<26;i++)
            if((!m1[i] && m2[i]) ||(!m2[i] && m1[i]))return false;
        sort(m1.begin(),m1.end());
        sort(m2.begin(),m2.end());
        for(int i=0;i<26;i++)if(m1[i]!=m2[i])return false;
        return true;
    }
};