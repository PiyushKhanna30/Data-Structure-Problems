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
    int result;

    public int pseudoPalindromicPaths(TreeNode root) {
        result = 0;
        Set<Integer> set = new HashSet<>();
        pseudoPalindromicPathsHelper(root, set);
        return result;
    }

    private void pseudoPalindromicPathsHelper(TreeNode root, Set<Integer> set) {
        if (root == null) return;
        if (set.contains(root.val))
            set.remove(root.val);
        else
            set.add(root.val);
        if (root.left == null && root.right == null && (set.size() == 0 || set.size() == 1)) {
            result += 1;
            return;
        }
        pseudoPalindromicPathsHelper(root.left, new HashSet(set));
        pseudoPalindromicPathsHelper(root.right, new HashSet(set));
    }
}
