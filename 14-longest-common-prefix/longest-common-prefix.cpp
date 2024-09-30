class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string,int>mp;
        int mx = 0;
        string ans;
        for(auto str:strs)
        {
            string s;
            for(auto i:str)
            {
                s+=i;
                mp[s]++;
            }
        }
        int n = strs.size();
        for(auto i:mp)
        {
            if(i.second==n && i.first.size()>mx){
                ans = i.first;
                mx = i.first.size();
            }
        }
        return ans;
    }
};