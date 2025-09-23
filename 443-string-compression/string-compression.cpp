class Solution {
public:
    int compress(vector<char>& s) {
        int i = 1, right = 1, n = s.size();
        while(i<n)
        {
            int c = 1;
            while(i< n && s[i]==s[i-1]){
                c++;
                i++;
            }
            if(c>1){
                string count = to_string(c);
                for(auto k:count){
                    s[right++] = k;
                }
            }
            if(i==n)break;
            s[right++] = s[i++];
        }
        for(auto i:s)cout<<i;
        return right;
    }
};