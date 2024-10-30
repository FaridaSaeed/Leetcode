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
const int N = 2005;
class Solution {
public:
    vector<vector<int>> bfs(TreeNode* root)
    {
        vector<vector<int>>res(N);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,int>lvl;
        q.push(root);
        lvl[root] = 0;
        res[0].push_back(root->val);
        while(!q.empty())
        {
            TreeNode* f = q.front();
            q.pop();
            if(f!=NULL && f->left!=NULL && lvl.find(f->left)==lvl.end())
            {
                q.push(f->left);
                res[lvl[f]+1].push_back(f->left->val);
                lvl[f->left] = lvl[f]+1;
            }
            if(f!=NULL && f->right!=NULL && lvl.find(f->right)==lvl.end())
            {
                q.push(f->right);
                res[lvl[f]+1].push_back(f->right->val);
                lvl[f->right] = lvl[f]+1;
            }
        }
        vector<vector<int>>ans;
        for(auto i:res)if(!i.empty())ans.push_back(i);
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        return bfs(root);
    }
};