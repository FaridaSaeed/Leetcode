class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_map<char,int>tmp;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(!mp.count(s[i])){
                if(tmp[t[i]])return false;
                mp[s[i]] = t[i];
                tmp[t[i]] = 1;
            }
            else
                if(mp[s[i]]!=t[i])return false;
        }
        return true;
    }
};