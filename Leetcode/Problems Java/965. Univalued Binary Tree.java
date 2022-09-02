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
    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return true;
        boolean ans = true;
        if (root.left != null)
            ans = (root.val == root.left.val) && ans;
        if (root.right != null)
            ans = (root.val == root.right.val) && ans;
        return ans && isUnivalTree(root.left) && isUnivalTree(root.right);
    }
}
