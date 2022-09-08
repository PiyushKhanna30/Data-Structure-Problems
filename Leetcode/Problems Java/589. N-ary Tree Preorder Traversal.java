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
    List<Integer> res;

    public List<Integer> preorder(Node root) {
        res = new ArrayList<>();
        preorderHelper(root, res);
        return res;
    }

    private void preorderHelper(Node root, List<Integer> res) {
        if (root == null) return;
        res.add(root.val);
        for (Node child : root.children)
            preorderHelper(child, res);
    }
}