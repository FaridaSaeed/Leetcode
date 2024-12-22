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
    int mx = 0;
    void dfs(TreeNode* root, int prev, int sum)
    {
        if(root==NULL){
            mx = max(mx,sum);
            return;
        }
        if(prev==0)
        {
            dfs(root->right,1,sum+1);
            dfs(root->left,0,1);
        }
        else
        {
            dfs(root->left,0,sum+1);
            dfs(root->right,1,1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left,0,1);
        dfs(root->right,1,1);
        return mx-1;
    }
};