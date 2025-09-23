class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=1;i<n;i++)
            nums[i]+=nums[i-1];
        int l = 0, r = l+k-1;
        double ans = INT_MIN;
        while(r<n)
        {
            double x = nums[r]-(l?nums[l-1]:0);
            ans = max(ans,x);
            l++,r++;
        }
        return ans/k;
    }
};