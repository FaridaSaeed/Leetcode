class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>d;
        for(auto i:nums)d.push_back(i);
        while(k--)
        {
            int x = d.back();
            d.pop_back();
            d.push_front(x);
        }
        int n = nums.size();
        for(int i=0;i<n;i++)nums[i] = d[i];
    }
};