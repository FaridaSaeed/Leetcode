class Solution {
public:
    bool isVowel(char x)
    {
        string vowel = "aeiou";
        for(auto i:vowel)
            if(i==x)return true;
        return false;

    }
    int maxVowels(string s, int k) {
        int l = 0, r = 0, n = s.size(), c=0 , ans = 0;
        while(r<n)
        {
            if(isVowel(s[r]))c++;
            if(r-l+1==k)
            {
                ans = max(ans,c); 
                if(isVowel(s[l]))c--;
                l++;
            }
            r++;
        }  
        return ans;
    }
};