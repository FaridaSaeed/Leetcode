class Solution {
public:
    vector<int>ans;
    vector<vector<int>>adj;
    vector<bool>vis;
    vector<bool>parent;
    bool cycled;
    void dfs_cycled(int node)
    {
        for (auto i: adj[node] )
        {
            if (parent[i])
                cycled=true ;
            else if (!vis[i])
            {
                parent[node] = true ;
                dfs_cycled(i);
            }
        }
        vis[node] = true ;
        parent[node] = false ;
    }
    void dfs(int c)
    {
        vis[c] = true;
        for(auto i:adj[c])
        {
            if (parent[i])
                cycled=true ;
            else if(!vis[i])
            {
                parent[c] = true ;
                dfs(i);
            }
        }
        parent[c] = false ;
        ans.push_back(c);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses+5);
        adj.resize(numCourses+5);
        parent.resize(numCourses+2,0);

        cycled = false;
        for(auto i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++)if(!vis[i])dfs(i);
        vector<int>v;
        if(cycled)return v;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};