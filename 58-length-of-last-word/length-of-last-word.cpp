class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        int ans = 0, x = 0;
        for(int i=n;i>=0;i--)
        {
            while(i>=0 && (s[i]-' ')!=0){
                x = 1;
                ans++;
                i--;
            }
            if(x) return ans;
        }
        return ans;
    }
};