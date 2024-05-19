class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char,int>mp,tt;
        for(auto i:s)mp[i]++;
        if(mp.size()==s.size())return s;
        map<int,vector<char>>m;
        for(auto i:mp)
        {
            m[i.second].push_back(i.first);
        }
        auto it = m.end();
        it--;
        string ans;
        for(auto i:it->second)
        {
            for(int j= s.size()-1;j>=0;j--)
            {
                if(s[j]==i)
                {
                    tt[s[j]] = j;
                    break;
                }

            }
        }
        map<int,char>m2;
        for(auto i:tt)
        {
            //cout<<i.first<<' '<<i.second<<'\n';
            m2[i.second] = i.first;
        }
        for(auto i:m2)ans+=i.second;
        return ans;
    }
};