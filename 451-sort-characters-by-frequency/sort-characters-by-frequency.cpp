class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        map<int,vector<char>>m;
        for(auto i:s)mp[i]++;
        for(auto i:mp){
            m[i.second].push_back(i.first);
        }
        string ans;
        for(auto i:m)
        {
            for(auto j:i.second)
            {
                for(int k=0;k<i.first;k++)
                    ans+=j;

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};