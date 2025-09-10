class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>ransom,mag;
        for(auto i:ransomNote)ransom[i]++;
        for(auto i:magazine)mag[i]++;
        for(auto i:mag)
            if(i.second<ransom[i.first])
                return false;
        for(auto i:ransom)
            if(i.second>mag[i.first])return false;
        
        return true;
    }
};