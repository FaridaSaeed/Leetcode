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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val==key)
        {
            if(!root->left && !root->right){
                
                root = nullptr;
            }
            else if(!root->left)root = root->right;
            else if(!root->right)root = root->left;
            else
            {
                TreeNode* tmp = root;
                TreeNode* prev = tmp;
                tmp = tmp->right;
                if(tmp->left){
                    while(tmp->left)
                    {
                        prev = tmp;
                        tmp = tmp->left;
                    }
                    root->val = tmp->val;
                    prev->left = tmp->right;
                }
                else
                {
                    root->val = tmp->val;
                    prev->right = tmp->right;
                }
            }
        }
        else
        {
            root->left = deleteNode(root->left,key);
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};