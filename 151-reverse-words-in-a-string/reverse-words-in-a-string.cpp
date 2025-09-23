class Solution {
public:
    string reverseWords(string s) {
        int i = 0 ,right = 0, n = s.size();
        while(i<n)
        {
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i]!=' ')s[right++] = s[i++];
            while(i<n && s[i]==' ')i++;
            if(i==n)break;
            s[right++] = ' ';

        }
        s.resize(right);
        i = 0;
        while(i<right)
        {
            int x = i;
            while(i<right && s[i]!=' ')i++;
            reverse(s.begin()+x, s.begin()+i);
            i++;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};