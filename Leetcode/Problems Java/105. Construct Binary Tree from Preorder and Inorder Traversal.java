/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder,int sp, int ep, int[] inorder, int si, int ei){
        if(sp>ep || si>ei)return null;
        
        TreeNode root = new TreeNode(preorder[sp]);

        int index = si;
        while(preorder[sp] != inorder[index]){
            index+=1;
        }
        
        int leftStart_ip = si;
        int leftEnd_ip = index-1;
        int leftStart_sp =  sp+1;
        int leftEnd_sp = leftEnd_ip - leftStart_ip + leftStart_sp;
        
        int rightStart_ip = index+1;
        int rightEnd_ip = ei;
        int rightStart_sp =  leftEnd_sp+1;
        int rightEnd_sp = ep;
        
        root.left = buildTree(preorder, leftStart_sp, leftEnd_sp, inorder, leftStart_ip, leftEnd_ip);
        root.right = buildTree(preorder, rightStart_sp, rightEnd_sp, inorder, rightStart_ip, rightEnd_ip);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1);
    }
}
