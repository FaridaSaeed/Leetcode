class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1,mx = 0;
        while(r>l)
        {
            if(height[r]>height[l])
            {
                mx = max(mx,height[l]*(r-l));
                l++;
            }
            else
            {
                mx = max(mx,height[r]*(r-l));
                r--;
            }
        }
        return mx;
    }
};