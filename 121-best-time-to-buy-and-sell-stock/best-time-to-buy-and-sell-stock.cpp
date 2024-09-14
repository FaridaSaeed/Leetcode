class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0,r = 1,n = prices.size();
        int mx = 0;
        while(l<=r && r<n)
        {
            if(prices[r]<prices[l])
                l = r;
            else
                mx = max(mx,prices[r]-prices[l]);
            r++;
        } 
        return mx;
    }
};