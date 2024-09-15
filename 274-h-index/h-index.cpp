class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int mx = min(citations[0],n);
        for(int i=0;i<n;i++)
        {
            if(citations[i]<=n-i)
                mx = max(mx,citations[i]);
            else 
                mx = max(mx,n-i);
        }
        return mx;
    }
};