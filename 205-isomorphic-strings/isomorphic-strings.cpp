class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char>mp;
        unordered_map<char,char>mpt;
        for(int i=0;i<n;i++){
            mp[s[i]] = t[i];
            if(mpt.find(t[i])!=mpt.end() && mpt[t[i]]!=s[i])return false;
            mpt[t[i]] = s[i];
        }
        for(int i=0;i<n;i++){
            s[i] = mp[s[i]];
        }
        return s==t;
    }
};