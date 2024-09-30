class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string str,st;
        int ind = 0;
        unordered_map<char,string>mp;
         unordered_map<string,char>mp1;
        for(auto i:s)
        {
            if(i>='a' && i<='z')
            {
                str+=i;
                st+=i;
            }
            else 
            {

                mp[pattern[ind]] = str;
                if(mp1.find(str)!=mp1.end() &&mp1[str]!=pattern[ind] )return false;
                mp1[str] = pattern[ind];
                ind++;
                str.clear();
            }
        }
        if(mp1.find(str)!=mp1.end() &&mp1[str]!=pattern[ind] )return false;
        mp[pattern[ind]] = str;
        mp1[str] = pattern[ind];
        str.clear();
        ind++;
        if(ind<pattern.size())return false;
        for(auto i:pattern){
            str+=mp[i];
        }

        return st==str;

    }
};