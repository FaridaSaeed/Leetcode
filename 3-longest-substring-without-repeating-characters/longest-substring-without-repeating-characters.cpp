class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int  l = 0,r = 0,n = s.size();
        int ans = 0,sum = 0;
        unordered_map<char,int>mp;
        while(r<n)
        {
            if(mp[s[r]])
            {
                while(s[l]!=s[r])
                {
                    mp[s[l]] = 0;
                    l++;
                }
                mp[s[l]] = 0;
                l==r?r=++l: l++;

            }
            else
            {
                ans = max(ans,r-l+1);
                mp[s[r]]++;
                r++;
            }
        }
        return ans;
    }
};