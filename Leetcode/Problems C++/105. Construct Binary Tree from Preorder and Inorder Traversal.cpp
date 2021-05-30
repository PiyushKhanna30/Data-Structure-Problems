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
    TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder,int psi,int pei,int isi,int iei)
    {
        if(psi>pei || isi>iei)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[psi]);
        int rootIndex=0;
        
        while(inorder[rootIndex]!=preorder[psi]) rootIndex++;
        
        int lpsi = psi+1;
        int lisi = isi;
        int liei = rootIndex-1;
        int lpei = liei - lisi + lpsi;
        
        int rpsi = lpei +1;
        int rpei = pei;
        int risi = rootIndex+1;
        int riei = iei;
        
        root->left = buildTreeHelp(preorder,inorder,lpsi,lpei,lisi,liei);
        root->right = buildTreeHelp(preorder,inorder,rpsi,rpei,risi,riei);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelp(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};