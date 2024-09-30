class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size() , m = needle.size();
        for(int i = 0;i<n;i++)
        {
            if(haystack[i] == needle[0])
            {
                int x = i;
                int j = 1;
                for(j = 1;j<m;j++)
                {
                    x++;
                    if(x>=n)break;
                    if(haystack[x]!=needle[j])break;
                }
                if(j==m)return i;
            }
        }
        return -1;
    }
};