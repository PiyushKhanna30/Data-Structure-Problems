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
    int cur_val,cur_count,max_count,num_modes;
    vector<int>ans;
    Solution()
    {
        cur_val=cur_count=max_count=num_modes=0;
    }
    void help(int val,bool add=false)
    {
        if(cur_val==val)
        {
            cur_count += 1;
        }
        else
        {
            cur_val = val;
            cur_count = 1;
        }
        if(max_count<cur_count)
        {
            max_count = cur_count;
            num_modes = 1;
        }
        else if(max_count == cur_count)
        {
            num_modes += 1;
            if(add)
            {
                ans.push_back(val);
            }
        }
    }
    void inorder(TreeNode* root,bool add = false)
    {
        if(!root)
            return;
        inorder(root->left,add);
        help(root->val,add);
        inorder(root->right,add);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        cur_val=cur_count=0;
        inorder(root,true);
        return ans;
    }
};
