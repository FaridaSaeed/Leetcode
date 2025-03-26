class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    int n;
    void rec(vector<int>&c,int i,int target){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i>=n)return;
        for(int ind = i;ind<n;ind++)
        {
            if(ind>i && c[ind]==c[ind-1])continue;
            if(target>=c[ind])
            {
                v.push_back(c[ind]);
                rec(c,ind+1,target-c[ind]);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        rec(candidates,0,target);
        return ans;
    }
};