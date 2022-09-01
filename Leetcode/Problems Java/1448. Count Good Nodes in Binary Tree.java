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
    int ans;

    public int goodNodes(TreeNode root) {
        List<Integer> temp = new ArrayList<>();
        ans = 0;
        check(root, Integer.MIN_VALUE);
        return ans;
    }

    private void check(TreeNode root, int x) {
        if (root == null) return;
        if (x <= root.val)
            ans += 1;
        check(root.left, Math.max(x, root.val));
        check(root.right, Math.max(x, root.val));
    }
    
}
// Preorder Traversal
// Keep track of previous maximum
// check if curr>= prevMax ans+1
// Call children with new max value
