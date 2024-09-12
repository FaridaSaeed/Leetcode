class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int c = 0;
        int cnt = 1,lst = 1,ans = 0;
        for(int i=0;i<n-1;i++)
        {
            if(i && s[i]!=s[i-1])c = 1;
            while(i<n-1 && s[i]==s[i+1]){
                cnt++;
                i++;
            }

            if(c){

                ans+=min(lst,cnt);
            }
            lst = cnt;
            cnt = 1;
        }
        if(n>1 && s[n-1]!=s[n-2])ans++;
        return ans;
    }
};