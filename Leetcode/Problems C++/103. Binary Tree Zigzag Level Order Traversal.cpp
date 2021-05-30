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
/*
Approch 2 stack approach
1.push root node to stack 1,explore the st1 till it is empty and push all the nodes poped into sa (small vector).
2.when stack 1 explored now switch flag, push sa to ans and clear sa.
3.repeat process for stack 2 but now push in reverse order like right node then left node.  
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        vector<int>sa;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        int x=1;
        int t;
        st1.push(root);
        TreeNode *temp=NULL;
        while(!st1.empty() || !st2.empty())
        {
            t=x;
            if(x==1 && !st1.empty())
            {
                temp=st1.top();
                st1.pop();
                if(st1.empty())
                    t=2;
                sa.push_back(temp->val);
                if(temp->left)
                    st2.push(temp->left);
                if(temp->right)
                    st2.push(temp->right);
            }
            else if(x==2 && !st2.empty())
            {
                temp=st2.top();
                st2.pop();
                if(st2.empty())
                    t=1;
                sa.push_back(temp->val);
                if(temp->right)
                    st1.push(temp->right);
                if(temp->left)
                    st1.push(temp->left);
            }
            if(t!=x)
            {
                x=t;
                ans.push_back(sa);
                sa.clear();
            }
        }
        return ans;
    }
};