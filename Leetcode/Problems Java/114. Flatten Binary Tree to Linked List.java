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
    public void flatten(TreeNode root) {
        while(root!=null){
            if(root.left!=null){
                TreeNode left = root.left;
                TreeNode temp = left;
                while(temp.right!=null)
                    temp = temp.right;
                temp.right = root.right;
                root.left = null;
                root.right = left;
            }
            root = root.right;
        }
    }
}
