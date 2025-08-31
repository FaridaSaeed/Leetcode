class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx = 0,n =0;
        for(auto i:nums)
        {
            if(mx==0)n = i;
            if(n==i)mx++;
            else mx--;
        }
        return n;
    }
};