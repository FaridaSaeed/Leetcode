class Solution {
public:
    void makeParen(int open,int close, string str1,vector<string>&v)
    {
        if(open==0 && close==0){
            v.push_back(str1);
            return;
        }

        if(open>0)makeParen(open-1,close,str1+"(",v);
        if(close>open)makeParen(open,close-1,str1+")",v);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        makeParen(n,n,"",v);
        return v;
    }
};