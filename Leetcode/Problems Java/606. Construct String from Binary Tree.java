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
    StringBuilder str;
    public void tree2strHelper(TreeNode root){
        if(root == null)return;
        str.append(root.val);
        
        if(root.left == null && root.right == null)
            return;
        
        if(root.left!=null){
            str.append('(');
            tree2strHelper(root.left);
            str.append(')');
        }
        else{
            str.append('(');
            str.append(')');
        }
        
        if(root.right!=null){
            str.append('(');
            tree2strHelper(root.right);
            str.append(')');
        }
    }
    public String tree2str(TreeNode root) {
        str = new StringBuilder();
        tree2strHelper(root);
        return str.toString();
    }
}