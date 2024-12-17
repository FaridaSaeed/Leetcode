class Solution {
public:
    bool isVowl(char c)
    {
        return(c=='a' || c=='e' || c=='o' || c=='i' || c=='u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int l = 0,r = 0;
        int c = 0,mx = 0;
        while(l<= r&& r<n)
        {
            if(isVowl(s[r]))
            {
                c++;
                mx = max(mx,c);
            }
            if(r-l+1==k)
            {
                if(isVowl(s[l]))c--;
                l++;
            }
            r++;

        }
        return mx;
    }
};