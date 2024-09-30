class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string>mp;
        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";
        vector<int>v = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans;
        int n = v.size();
        for(int i=n-1;i>=0;i--)
        {
            while(num>=v[i])
            {
                ans+=mp[v[i]];
                num-=v[i];
            }
        }
        return ans;
        
    }
};