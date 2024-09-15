class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        
        int n = nums.size();
        int mx = 0;
        for(int i= 0;i<n-1;i++)
        {
            if(i<=mx && i+nums[i]>=mx)mx = i+nums[i];
            nums[i] = mx;
        }
        
        int currentIndex = 0;
        int jumps = 0;
        
        while (currentIndex < nums.size() - 1) {
            ++jumps;
            currentIndex = nums[currentIndex];
        }
        
        return jumps;
    }
};