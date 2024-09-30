class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1,mp2;
        for(auto i:ransomNote)mp1[i]++;
        for(auto i:magazine)mp2[i]++;
        for(auto i:mp1)
        {
            if(mp2[i.first]<i.second)return false;
        }
        return true;
    }
};