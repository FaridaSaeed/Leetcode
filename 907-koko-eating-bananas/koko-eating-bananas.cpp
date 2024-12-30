class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1 , r = 1e9,mid;
        while(l<r)
        {
            mid = l+(r-l)/2;
            int x = 0;
            for(auto i :piles)
            {
                x+=(i+mid-1)/mid;
            }
            if(x>h)l = mid+1;
            else r = mid;
        }
        return r;
    }
};
