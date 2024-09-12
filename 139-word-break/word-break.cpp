class Solution {
public:
    int n , len;
    set<string> word ;
    string s;

    int dp[20020];

    bool rec(int lev ) {
        if (lev == len) {
            return true ;
        }
        if (dp[lev] != -1) return dp[lev];
        bool canJoin = false ;

        for (int i = lev  ; i < len ; i++ ) {
            if (word.find(s.substr(lev, i - lev + 1)) != word.end() and  rec(i + 1)) {
                canJoin = true ;
                break;
            }
        }
        return dp[lev] = canJoin ;
    }
    bool wordBreak(string ss, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        for(auto it : wordDict){
            word.insert(it);
        }
        s = ss;
        len = s.size();
        return rec(0);
    }
};