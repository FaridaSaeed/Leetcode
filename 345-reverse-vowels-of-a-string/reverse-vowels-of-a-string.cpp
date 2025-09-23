class Solution {
public:
    bool isVowel(char x)
    {
        string vowels = "aeiou";
        for(auto i:vowels)
        {
            if(tolower(x)==i)return true;
        }
        return false;

    }
    string reverseVowels(string s) {
        int left = 0 , right = s.size()-1;

        while(left<right)
        {
            bool fleft = isVowel(s[left]), fright =isVowel(s[right]) ;
            if(fleft && fright){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(fleft)right--;
            else if(fright)left++;
            else {
                left++;
                right--;
            }
        }
        return s;

    }
};