class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //sort(points.begin(),points.end());
        int n = points.size();
        int mx = 1;
        for(int i=0;i<n;i++)
        {
            unordered_map<double,int>mp;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                int x = points[j][0]-points[i][0];
                int y = points[j][1]-points[i][1];
                double z = 0;
                if(x==0)z = INT_MAX;
                else z = 1.0*y/x;
                mp[z]++;
                mx = max(mx,mp[z]+1);
            }
        }
        return mx;
    }
};