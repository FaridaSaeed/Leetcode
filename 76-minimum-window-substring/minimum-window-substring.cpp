class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp,mps;
        for(auto i:t)mp[i]++;
        for(auto i:s)mps[i]++;
        for(auto i:mp)if(mps[i.first]<i.second)return "";
        int n = s.size();
        mps.clear();
        int cnt = 0;
        int l = 0,r = 0;
        int ansl = 0,mn = 1e9;
        int m = mp.size();
        while(r<n)
        {
            mps[s[r]]++;
            if(mp.find(s[r])!=mp.end() && mps[s[r]]==mp[s[r]] && cnt!=m)
                cnt++;
            if(cnt==m)
            {
                while(mps[s[l]]>mp[s[l]])
                {
                    mps[s[l]]--;
                    l++;
                }
                if(r-l+1<mn)
                {
                    mn = r-l+1;
                    ansl = l;
                }
            }
            r++;
        }
        return s.substr(ansl,mn);
    }
};