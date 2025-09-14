const int N = 2005;
class Solution {
public:
    vector<int>adj[N];
    bool vis[N];
    bool par[N];
    vector<int>ans;
    bool cycle;
    bool dfsCycle(int x)
    {
        vis[x] = true;
        par[x] = true;
        for(auto i:adj[x])
        {
            if(par[i])
                return true;
            else if(!vis[i] && dfsCycle(i)) {

                return true;
            }
        }
        par[x] = false;
        return false;

    }
    void dfs(int x)
    {
        for(auto i:adj[x])
            if(!vis[i])
                dfs(i);
        vis[x] = true;
        ans.push_back(x);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i:prerequisites)
            adj[i[0]].push_back(i[1]);
        
        for(int i=0;i<numCourses;i++)
            if(!vis[i])
                if(dfsCycle(i)) return ans;
        memset(vis,0,sizeof vis);
        for(int i=0;i<numCourses;i++)
            if(!vis[i]) dfs(i);
        return ans;
    }
};