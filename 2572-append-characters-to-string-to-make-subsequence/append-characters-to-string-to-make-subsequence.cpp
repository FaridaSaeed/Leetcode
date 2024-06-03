class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0 , r = 0 , c = 0;
        while(l<=r && r<s.size() && c<s.size())
        {
            if(s[r] == t[c])
            {
                l = r++;
                c++;
            }
            else r++;
        }
        return t.size()-c;
    }
};