/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ 
class Solution {
public:
    map<int,vector<int>>mp;
    void bfs(TreeNode* root, int lvl)
    {
        if(root==NULL)return ;
        mp[lvl].push_back(root->val);
        bfs(root->left,lvl+1);
        bfs(root->right,lvl+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        bfs(root,0);
        vector<double>ans;
        for(auto i:mp)
        {
            int n = i.second.size();
            cout<<n<<' ';
            long long sum = 0;
            for(auto j:i.second)sum+=j;
            double d = sum*1.0/n;
            ans.push_back(d);
            
        }   
        return ans;
    }
};