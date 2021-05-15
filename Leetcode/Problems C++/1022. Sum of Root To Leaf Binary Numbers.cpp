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
    int ans;
    Solution()
    {
        ans = 0;
    }
    void preorder(TreeNode *root, int curr)
    {
        if(root)
        {
            curr = curr << 1 ;
            curr += root->val;
            if(root->left==nullptr && root->right==nullptr)
            {
                cout<<curr<<" ";
                ans+=curr;
                return;
            }
            preorder(root->left,curr);
            preorder(root->right,curr);
        }
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return ans;
    }
};