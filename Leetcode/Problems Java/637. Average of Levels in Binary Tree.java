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
    Queue<TreeNode> queue;
    List<Double> ans;

    public List<Double> averageOfLevels(TreeNode root) {
        ans = new ArrayList<>();
        if (root == null) return ans;
        queue = new LinkedList<>();
        TreeNode temp = new TreeNode();
        queue.add(root);
        queue.add(temp);
        double average = 0.0d;
        int countNodes = 0;
        while (!queue.isEmpty() && queue.peek() != temp) {
            TreeNode frontNode = queue.poll();
            average += frontNode.val;
            countNodes += 1;
            if (frontNode.left != null) queue.add(frontNode.left);
            if (frontNode.right != null) queue.add(frontNode.right);
            if (queue.peek() == temp) {
                queue.poll();
                queue.add(temp);
                ans.add(average / countNodes);
                average = 0.0d;
                countNodes = 0;
            }
        }
        return ans;
    }
}
