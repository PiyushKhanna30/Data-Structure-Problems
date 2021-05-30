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
        ans=0;
    }
    int h(TreeNode* r)
    {
        if(!r)
            return 0;
        int a = h(r->left);
        int b = h(r->right);
        ans = max(ans,a+b);
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        h(root);
        return ans;
    }
};


/*

class Solution {
public:
    int h(TreeNode *r)
    {
        if(!r)
            return 0;
        return max(h(r->left),h(r->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        return max(h(root->left)+h(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};
*/