/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    TreeNode newRoot;

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        addOneRow(root, val, depth, 1);
        return root;
    }

    private void addOneRow(TreeNode root, int val, int depth, int curDepth) {
        if (root == null) return;
        if (depth == curDepth + 1) {
            TreeNode tempL = root.left;
            TreeNode tempR = root.right;
            root.left = new TreeNode(val);
            root.right = new TreeNode(val);
            root.left.left = tempL;
            root.right.right = tempR;
            return;
        }
        addOneRow(root.left, val, depth, curDepth + 1);
        addOneRow(root.right, val, depth, curDepth + 1);
    }
}
