class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int ans = 0 , l = 0 ,r = n-1;
        while(l<r)
        {
            if(height[l]>=height[r])
            {
                ans = Math.max(height[r]*(r-l),ans);
                r--;
            }
            else 
            {
                ans = Math.max(height[l]*(r-l),ans);
                l++;
            }
        }
        return ans;
    }
}