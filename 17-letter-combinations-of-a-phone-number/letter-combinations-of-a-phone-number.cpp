class Solution {
public:
    vector<string>ans;
    string s;
    int n;
    unordered_map<char,string>mp;
    void rec(string d,int ind)
    {
        if(ind>=n){
            ans.push_back(s);
            return;
        }
        for(auto c:mp[d[ind]])
        {
            s+=c;
            rec(d,ind+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n==0)return  ans;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        rec(digits,0);
        return ans;
    }
};