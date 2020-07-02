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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //INITIALIZING ans VECTOR
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        
        //STORING TREENODE's IN QUEUE AND PROCESSING THEM 
        queue<TreeNode *>q;
        q.push(root);
        ///CREATING NULL TREENODE TO KEEP TRACK WHEN LEVEL FINISHES AND PUSH TO q 
        TreeNode* nul=new TreeNode(0);
        q.push(nul);
        
        ///VECTOR TO MAINTAIN EACH LEVEL AND BOOL TO MARK END OF LEVEL
        vector<int>sa;
        bool lvl_done=false;
        while(!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            if(q.front()==nul)
            {
                q.pop();
                lvl_done=true;
            }
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
            sa.push_back(t->val);
            if(lvl_done)
            {
                ans.push_back(sa);
                sa.clear();
                q.push(nul);
                lvl_done=false;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};