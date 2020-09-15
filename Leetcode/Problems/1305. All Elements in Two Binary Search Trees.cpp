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
    void merge(vector<int>&result,vector<int>&res1,vector<int>&res2)
    {
        int i=0,j=0;
        while(res1.size()!=i && res2.size()!=j)
        {
            if(res1[i]<res2[j])
            {
                result.push_back(res1[i++]);
            }
            else
            {
                result.push_back(res2[j++]);
            }
        }
        while(res1.size()!=i)
            result.push_back(res1[i++]);
        while(res2.size()!=j)
            result.push_back(res2[j++]);
    }
    void allElements(TreeNode* root,vector<int>&result)
     {
         if(root!=NULL)
         {
             allElements(root->left,result);
             result.push_back(root->val);
             allElements(root->right,result);
         }
     }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>result,res1,res2;
        allElements(root1,res1);
        allElements(root2,res2);
        merge(result,res1,res2);
        return result;
    }
};