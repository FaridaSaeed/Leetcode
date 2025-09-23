class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), l = 0, r = n-1;
        int  c = 0;
        while(l<r)
        {
            int sum = nums[l]+nums[r];
            if(sum>k)r--;
            else if(sum<k)l++;
            else 
            {
                c++;
                l++;
                r--;
            }
        }
        return c;
    }
};