class Solution {
public:
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses+2,0);
        adj.resize(numCourses+2);
        parent.resize(numCourses+2,0);

        cycled = false;
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        bool ans = true;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i]){
                dfs_cycled(i);
            }
        }
        return !cycled;
    }
};