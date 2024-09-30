class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        bool f = false;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(((s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z')))
            {
                f = true;
                ans++;
            }
            else if(f)break;
        }
        return ans;
    }
};