class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            if((goal&(1<<i))!=(start&(1<<i)))ans++;
        }
        return ans;
    }
};
