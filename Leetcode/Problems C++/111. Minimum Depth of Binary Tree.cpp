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
    int minDepth(TreeNode* root) {
        if(root)
        {
            if(!root->left && !root->right)
                return 1;
            int a = INT_MAX,b = INT_MAX;
            if(root->left)
                a = minDepth(root->left);
            
            if (root->right)
                b = minDepth(root->right);
        
        return min(a,b)+1;
        }
        return 0;
    }
};