class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mps,mp;
        for(auto i:t)mp[i]++;
        int l = 0 ,r = 0;
        int n = s.size();
        int cnt = 0,mx = 1e9,mnl=0,mnr=0;
        string ans;
        while(r<n)
        {
            if(l==r && mp.find(s[r])==mp.end())
            {
                l =++r;
                continue;
            }
            if(mp.find(s[r])!=mp.end())
            {
                if(mps[s[r]]<mp[s[r]])cnt++;
                mps[s[r]]++;
            }
            r++;
            while(cnt==t.size())
            {
                if(r-l<mx)
                {
                    mx = r-l;
                    mnl = l;
                    mnr = r;
                }
                if(mps.find(s[l])!=mps.end()){
                    mps[s[l]]--;
                    if(mps[s[l]]<mp[s[l]])cnt--;
                }
                l++;
            }
        }
        ans = s.substr(mnl,mnr-mnl);
        return ans;
    }
};