class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiou";
        int left = 0 , right = s.size()-1;

        while(left<right)
        {
            bool f1 = false, f2 = false;
            for(auto i:vowels)
            {
                if(tolower(s[left])==i)f1 = true;
                if(tolower(s[right])==i)f2 = true;
            }
            if(f1 && f2){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(f1)right--;
            else if(f2)left++;
            else {
                left++;
                right--;
            }
        }
        return s;

    }
};