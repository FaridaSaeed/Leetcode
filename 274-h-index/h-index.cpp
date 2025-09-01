class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>v(n+5);
        v[0] = n;
        for(int i=0;i<n;i++)v[min(n+1,citations[i]+1)]--;
        int ans = 0;
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
            if(v[i]>=i)ans = i;
        }
        return ans;

    }
};