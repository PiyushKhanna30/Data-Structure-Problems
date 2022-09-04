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
    Map<Integer, Map<Integer, List<Integer>>> map;
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    List<List<Integer>>ans;

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        map = new TreeMap<>();
        traverse(root, 0, 0);
        ans =new ArrayList<>();
        for (int key : map.keySet()) {
            System.out.print("Key : "+key+" ");
            List<Integer>smallAns = new ArrayList<>();
            for (List<Integer> s:map.get(key).values()){
                Collections.sort(s);
                smallAns.addAll(s);
            }
            ans.add(smallAns);
        }
        return ans;
    }

    private void traverse(TreeNode root, int vLevel, int hLevel) {
        if (root == null) return;
        max = Math.max(max, vLevel);
        min = Math.min(min, vLevel);
        map.putIfAbsent(vLevel, new TreeMap<>());
        map.get(vLevel).putIfAbsent(hLevel, new ArrayList<>());
        map.get(vLevel).get(hLevel).add(root.val);

        traverse(root.left, vLevel - 1, hLevel + 1);
        traverse(root.right, vLevel + 1, hLevel + 1);
    }
}
