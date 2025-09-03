class Solution {
public:
    string reverseWords(string s) {
        while(s.back()==' ')
            s.pop_back();
        reverse(s.begin(),s.end());
        while(s.back()==' ')
            s.pop_back();
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int j = i;
            while(i<n && s[i]!=' ')
                i++;
            reverse(s.begin()+j,s.begin()+i);
        }
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==' ' && s[i+1]==' ')
            {
                s.erase(s.begin()+i);
                i--;
            }
        }
        return s;

    }
};