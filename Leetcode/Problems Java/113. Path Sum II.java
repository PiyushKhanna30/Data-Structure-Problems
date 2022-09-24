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
    List<List<Integer>> ans;

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        ans = new ArrayList<>();
        pathSum(root, targetSum, new ArrayList<>());
        return ans;
    }

    public void pathSum(TreeNode root, int targetSum, List<Integer> res) {
        if (root == null) return;

        List<Integer> newRes = new ArrayList<>();
        newRes.addAll(res);
        newRes.add(root.val);
        
        if (root.left == null && root.right == null && targetSum == root.val) {
            ans.add(newRes);
            return;
        }

        pathSum(root.left, targetSum - root.val, newRes);
        pathSum(root.right, targetSum - root.val, newRes);
    }
}
