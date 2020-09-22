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
    int inorder_pred(TreeNode *root)
    {
        root = root->left;
        while(root->right)
            root=root->right;
        return root->val;
    }
    int inorder_succ(TreeNode *root)
    {
        root = root->right;
        while(root->left)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;
        if(root->val<key)
        {
            root->right = deleteNode(root->right,key);
        }
        else if(root->val>key)
        {
            root->left = deleteNode(root->left,key);
        }
        else
        {
            if(!root->left && !root->right)
            {
                root=NULL;
            }
            else if(root->left)
            {
                root->val = inorder_pred(root);
                root->left = deleteNode(root->left,root->val);
            }
            else
            {
                root->val = inorder_succ(root);
                root->right = deleteNode(root->right,root->val);
            }
            
        }
        return root;
    }
};