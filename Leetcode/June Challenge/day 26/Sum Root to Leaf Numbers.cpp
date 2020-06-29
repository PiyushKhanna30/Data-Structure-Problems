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
    int fun(TreeNode *root,int t)
    {
        t=t*10+root->val;
        if (root->left==NULL && root->right==NULL)
            return t;
        int a=0,b=0;
        if(root->left)
            a=fun(root->left,t);
        if(root->right)
            b=fun(root->right,t);
            
        return a+b;
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        return fun(root,0);
    }
};