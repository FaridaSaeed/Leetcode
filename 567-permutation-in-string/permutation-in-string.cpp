class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp,mp2;
        for(auto i:s1)mp[i]++;
        int l = 0,r = 0,n = s1.size(),m = s2.size(),c = 0;
        while(r<m)
        {
            if(mp[s2[r]])
            {
                if(mp2[s2[r]]+1<=mp[s2[r]])
                {   
                    mp2[s2[r]]++;
                    c++;
                    if(c==n)return true;
                    r++;
                }
                else {
                    c--;
                    mp2[s2[l]]--;
                    l++;
                }
            }
            else {
                mp2.clear();
                l = ++r;
                c = 0;
            }
        }
        return false;

    }
};