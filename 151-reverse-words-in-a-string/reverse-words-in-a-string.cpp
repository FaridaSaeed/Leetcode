class Solution {
public:
    string reverseWords(string s) {
        int right = 0,i=0,n = s.size();
        while(i<n)
        {
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i]!=' ')s[right++] = s[i++];
            while(i<n && s[i]==' ')i++;
            if(i==n)break;
            s[right++] = ' ';
        }
        s.resize(right);
        reverse(s.begin(),s.end());
        for(int i=0;i<right;i++)
        {
            int j = i;
            while(i<right && s[i]!=' ')
                i++;
            reverse(s.begin()+j,s.begin()+i);
        }
        return s;
    }
};