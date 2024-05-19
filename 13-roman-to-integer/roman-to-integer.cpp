class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0,i;
        for(i=0;i<s.size()-1;i+=2)
        {
            if(s[i]=='I' && s[i+1]=='V')ans+=4;
            else if(s[i]=='I' && s[i+1]=='X')ans+=9;
            else if(s[i]=='X' && s[i+1]=='L')ans+=40;
            else if(s[i]=='X' && s[i+1]=='C')ans+=90;
            else if(s[i]=='C' && s[i+1]=='D')ans+=400;
            else if(s[i]=='C' && s[i+1]=='M')ans+=900;
            else
            {
                ans+=mp[s[i]];
                i--;
            }

        }
        if(i==s.size()-1)ans+=mp[s[i]];
        return ans;
    }
};