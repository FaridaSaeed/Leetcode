class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1,mx =0;
        while(r<prices.size()){
            if(prices[r]<prices[l])l=r;
            else if(prices[r]-prices[l]>=mx)
                mx = prices[r]-prices[l];
            r++;
        }
        return mx;
    }
};