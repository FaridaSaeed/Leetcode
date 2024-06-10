class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>srtd = heights;
        sort(srtd.begin(),srtd.end());
        int c = 0;
        for(int i=0;i<heights.size();i++)if(heights[i]!=srtd[i])c++;
        return c;   
    }
};