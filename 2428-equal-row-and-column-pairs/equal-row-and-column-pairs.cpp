class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>cols(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cols[i].push_back(grid[j][i]);
        map<vector<int>,int>mp;
        int c = 0;
        for(auto i:grid)mp[i]++;
        for(auto i:cols){
            if(mp[i])c+=mp[i];
            //mp[i]++;
        }
        return c;
    }
};