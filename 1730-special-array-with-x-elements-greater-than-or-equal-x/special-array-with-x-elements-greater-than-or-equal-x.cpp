class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=100;i++)
        {
            int c = 0;
            for(auto j:nums)
            {
                if(j>=i)c++;
            }
            if(c==i)return i;
        }
        return -1;
    }
};