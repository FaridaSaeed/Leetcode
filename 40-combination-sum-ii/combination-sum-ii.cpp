const int N = 105 , M = 35;
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>res;
    void backtrack(vector<int>& candidates,int ind,int target)
    {
        if(target == 0){
            ans.push_back(res);
            return;
        }
        if(ind>=candidates.size())return;
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])continue; 
            if(target-candidates[i]>=0){
                res.push_back(candidates[i]);
                backtrack(candidates,i+1,target-candidates[i]);
                res.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target);
        return ans;
    }
};