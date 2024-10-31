class Solution {
public:
    bool f = false;
    double ans = 1.0;
    unordered_map<string,vector<pair<string,double>>>adj;
    unordered_map<string,int>vis;
    void dfs(string s,string d,double x)
    {
        vis[s] = true;
        if(f)return;
        if(s==d)
        {
            f = true;
            ans*=x;
            return ;
        }

        for(auto i:adj[s])
        {
            if(!vis[i.first])dfs(i.first,d,i.second);
        }
        if(f)ans*=x;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0;i<n;i++)
        {
            adj[equations[i][0]].emplace_back(equations[i][1],values[i]);
            adj[equations[i][1]].emplace_back(equations[i][0],1.0/values[i]);
        }
        vector<double>res;
        for(auto i:queries)
        {
            if(adj.find(i[0])==adj.end() || adj.find(i[1])==adj.end())
            {
                res.push_back(-1.0);
                continue;
            }
            ans = 1;
            f = false;
            vis.clear();
            dfs(i[0],i[1],1.0);
            if(f)
                res.push_back(ans);
            else res.push_back(-1.0);
        }
        return res;
    }
};