class Solution {
public:
    int hammingWeight(int n) {
        bitset<32>st(n);
        int c = 0;
        for(int i=0;i<st.size();i++)if(st[i])c++;
        return c;
    }
};