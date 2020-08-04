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
    int sumInTree(TreeNode *root,int sum)
    {
        if(root == NULL)
            return 0;
        if(sum == root->val)
            return 1+sumInTree(root->left,sum-root->val)+sumInTree(root->right,sum-root->val);
        return sumInTree(root->left,sum-root->val)+sumInTree(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        return sumInTree(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};