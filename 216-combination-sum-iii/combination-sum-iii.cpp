class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>&com,int start,int k,int n)
    {
        if(com.size()==k && n==0){
            ans.push_back(com);
            return;
        }
        for(int i = start+1;i<10;i++)
        {
           if(n<i)continue;
           com.push_back(i);
           backtrack(com,i,k,n-i);
           com.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>com;
        backtrack(com,0,k,n);
        return ans;
    }
};