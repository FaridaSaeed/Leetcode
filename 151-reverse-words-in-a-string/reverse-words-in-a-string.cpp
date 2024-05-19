class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string tt;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' '){
                tt+=s[i];
            }
            else 
            {
                reverse(tt.begin(),tt.end());
                if(!tt.empty())
                    ans.push_back(tt);
                tt = "";
            }
        }
        reverse(tt.begin(),tt.end());
        if(!tt.empty())
            ans.push_back(tt);
        string res;
        for(auto i:ans){
            res+=i+" ";
        }
        res.pop_back();
        return res;
    }
};