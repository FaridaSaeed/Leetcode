const int N = 1e4+5;
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n)
        {
            n/=5;
            ans+=n;
        }
        return ans;
    }
};