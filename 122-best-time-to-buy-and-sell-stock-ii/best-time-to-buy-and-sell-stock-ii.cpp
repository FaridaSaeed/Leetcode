class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, n = prices.size(),ans = 0;
        while(r<n)
        {
            if(prices[r]>prices[l])
            {
                while(r+1<n && prices[r]<prices[r+1])r++;
                ans += prices[r]-prices[l];
                r++;
                
            }
            l = r++;
        }
        return ans;
    }
};