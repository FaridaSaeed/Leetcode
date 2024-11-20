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
    vector<int>v;
    void preOrder(TreeNode* root)
    {
        if(root==NULL)return;
        v.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
        root = NULL;
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        preOrder(root);
        TreeNode* node = root;
        for(int i=1;i<v.size();i++)
        {
            if(node->right==NULL)
                node->right = new TreeNode(v[i]);
            else node->right->val = v[i];
            node->left = NULL;
            node = node->right;
        }
    }
};