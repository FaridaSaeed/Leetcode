class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre = nums;
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1];
        int l = 0, r = l+k-1;
        double ans = -1e5;
        while(r<n)
        {
            double x = (pre[r]-(l?pre[l-1]:0))/(k*1.0);
            ans = max(ans,x);
            l++,r++;
        }
        return ans;
    }
};