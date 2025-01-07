class Solution {
public:
    string reverseWords(string s) {
        int right = 0;
        int l = 0,r = 0,n = s.size();
        for(int i=0;i<n;)
        {
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i]!=' ')
                s[right++] = s[i++];
            if(i==n)break;
            s[right++] = ' ';

        }
        s.resize(right);
        if(s.back()==' ')s.pop_back();
        n = s.size();
        reverse(s.begin(),s.end());
        while(r<n)
        {
            if(s[r]!=' ')
                r++;
            else {
                reverse(s.begin()+l,s.begin()+r);
                l=++r;
            }

        }
        reverse(s.begin()+l,s.end());
        return s;
    }
};