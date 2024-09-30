class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string,int>mp;
        int mx = 0;
        int n = strs.size();
        string ans;
        for(auto str:strs)
        {
            string s;
            for(auto i:str)
            {
                s+=i;
                mp[s]++;
                if(mp[s]==n && s.size()>mx)
                {
                    mx = s.size();
                    ans = s;
                }
            }
        }
        return ans;
    }
};