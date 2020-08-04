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
    vector<vector<int>>ans;
    void pathSumHelp(TreeNode* root, int sum,vector<int>temp) {
        if(root == NULL)
            return;
        if(sum == root->val && root->left == NULL && root->right == NULL)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        temp.push_back(root->val);
        pathSumHelp(root->left,sum-root->val,temp);
        pathSumHelp(root->right,sum-root->val,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>temp;
        pathSumHelp(root,sum,temp);
        return ans;
    }
    
};
