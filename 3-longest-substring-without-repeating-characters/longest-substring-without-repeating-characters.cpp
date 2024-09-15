class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,r = 0,n = s.size(),mx = 0;
        unordered_map<char,int>freq,mp;
        while(r<n)
        {
            if(mp[s[r]]>l)
            {
                mx = max(mx,r-l);
                l = mp[s[r]];
                mp[s[r]] = r+1;
                r++;
            }
            else 
            {
                mp[s[r]] = r+1;
                r++;
            }
        }
        mx = max(mx,r-l);
        return mx;
    }
};