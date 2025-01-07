class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        int mx = 0,n = c.size();
        for(int i =0;i<n;i++)
        {
            if(n-i>=c[i])mx = max(mx,c[i]);
            else mx = max(mx,n-i);
        }
        return mx;
    }
};