class Solution {
public:
    string reverseWords(string s) {
        string nw;
        bool f = false;
        for(auto i:s)
        {
            if(i!=' ')
            {
                nw+=i;
                f = true;
            }
            else if(f){
                nw+=" ";
                f = false;
            }
        }
        if(nw.back()==' ')nw.pop_back();
        s = nw;
        reverse(s.begin(),s.end());
        int l = 0,r = 0,n = s.size();
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