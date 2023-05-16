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
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        // levelOrderRec(root, 0);
        levelOrderIter(root);
        return result;
    }
    private void levelOrderIter(TreeNode root){
        if(root==null)return;
        Queue<TreeNode>queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()){
            int listSize = queue.size();
            List<Integer>smallResult = new ArrayList<>();
            for(int i=0;i<listSize;i++){
                TreeNode node = queue.poll();
                if(node.left!=null)
                    queue.add(node.left);
                if(node.right!=null)
                    queue.add(node.right);
                smallResult.add(node.val);
            }
            result.add(smallResult);
        }
    }
    private void levelOrderRec(TreeNode root, int depth){
        if(root==null)return;
        depth+=1;
        if(result.size()<depth)
            result.add(new ArrayList<>());
        result.get(depth-1).add(root.val);
        levelOrderRec(root.left, depth);
        levelOrderRec(root.right, depth);
    }
}
