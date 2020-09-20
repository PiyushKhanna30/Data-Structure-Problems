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
    TreeNode* buildTreeHelp(vector<int>& postorder , vector<int>& inorder,int psi,int pei,int isi,int iei)
    {
        if(psi>pei || isi>iei)
            return nullptr;
        TreeNode* root = new TreeNode(postorder [pei]);
        int rootIndex=0;
        
        while(inorder[rootIndex]!=postorder [pei]) rootIndex++;
        
        int lpsi = psi;
        int lisi = isi;
        int liei = rootIndex-1;
        int lpei = liei - lisi + lpsi;
        
        int rpsi = lpei +1;
        int rpei = pei-1;
        int risi = rootIndex+1;
        int riei = iei;
        
        root->left = buildTreeHelp(postorder ,inorder,lpsi,lpei,lisi,liei);
        root->right = buildTreeHelp(postorder ,inorder,rpsi,rpei,risi,riei);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        return buildTreeHelp(po,in,0,po.size()-1,0,in.size()-1);
    }
};