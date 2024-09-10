class Solution {
public:
    vector<vector<int>>ans;
    vector<int>res;
    void backtrack(vector<int>& candidates, int target,int ind)
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
        int n = candidates.size();
        for(int i=ind;i<n;i++)
        {
            if(target-candidates[i]>=0){
                res.push_back(candidates[i]);
                backtrack(candidates,target-candidates[i],i);
                res.pop_back();

            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return ans;
    }
};