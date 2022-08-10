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
    private TreeNode sortedArrayToBSTHelper(int[] nums, int left, int right) {
        if (left > right) return null;
        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = sortedArrayToBSTHelper(nums, left, mid - 1);
        root.right = sortedArrayToBSTHelper(nums, mid + 1, right);
        return root;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.length - 1);
    }

//    public TreeNode sortedArrayToBST(int[] nums) {
//         if (nums.length == 0) return null;
//         int mid = nums.length / 2;
//         TreeNode root = new TreeNode(nums[mid]);

//         int[] left = Arrays.copyOfRange(nums, 0, mid);
//         root.left = sortedArrayToBST(left);
//         int[] right = Arrays.copyOfRange(nums, mid + 1, nums.length);
//         root.right = sortedArrayToBST(right);
//         return root;
//    }
}
