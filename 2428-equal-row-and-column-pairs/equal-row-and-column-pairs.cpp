class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int>mp;
        for(auto i:grid)mp[i]++;
        int c = 0;
        for(int i=0;i<n;i++)
        {
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[j][i]);
            }
            if(mp[v])
                c+=mp[v];
        }
        return c;
    }
};
