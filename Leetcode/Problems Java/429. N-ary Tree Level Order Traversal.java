/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    List<List<Integer>> res;
    Queue<Node> queue;

    public List<List<Integer>> levelOrder(Node root) {
        res = new ArrayList<>();
        if(root == null)return res;
        queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            List<Integer> subAns = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node temp = queue.poll();
                subAns.add(temp.val);
                for (Node child : temp.children)
                    queue.add(child);
            }
            res.add(subAns);
        }
        return res;
    }
}