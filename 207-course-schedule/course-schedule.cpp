const int N = 2005;
class Solution {
public:
    vector<int>adj[N];
    bool vis[N];
    bool par[N];
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i]){
                if(dfsCycle(i))return false;
            }
        }
        return true;
    }
};