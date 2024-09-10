class Solution {
public:
    vector<vector<int>>ans;
    vector<int>res;
    void backtrack(int i,int k,int n)
    {
        if(k==0){
            ans.push_back(res);
            return;
        }
        if(i<=n && k>0)
        {
            res.push_back(i);
            backtrack(i+1,k-1,n);
            res.pop_back();
        }
        if(i<n)
            backtrack(i+1,k,n);
        
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,k,n);
        return ans;
    }
};