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

//Time O(N) Space O(N)
class Solution {
    int cams = 0;
    Set<TreeNode>cameras;
    public int minCameraCover(TreeNode root) {
        cameras = new HashSet<>();
        //Add null in cameras as we donot wish to have cameras on leaf nodes
        cameras.add(null);
        //send node and its parent
        traverse(root, null);
        return cams;
    }
    public void traverse(TreeNode root, TreeNode parent){
        if(root==null)return;
        traverse(root.left, root);
        traverse(root.right, root);
        
        if((parent==null && !cameras.contains(root)) || !cameras.contains(root.left) || !cameras.contains(root.right)){
            cameras.add(root);
            cameras.add(root.left);
            cameras.add(root.right);
            cameras.add(parent);
            cams+=1;
        }
        
    }
}


//Time O(N) Space O(H)
class Solution {
    int cams = 0;
    public int minCameraCover(TreeNode root) {
        //0 no camera
        //1 under supervision
        //2 camera present
        
        int ans = traverse(root);
        
        //root node not covered when 0 
        return ans==0?cams+1:cams;
    }
    
    int traverse(TreeNode root){
        //say childs of leaf nodes
        if(root == null){
            return 1;
        }
        
        int left = traverse(root.left);
        int right = traverse(root.right);
        
        //no camera cover atleast 1 child   	01,10,00,02,20
        if(left==0 || right == 0){
            cams+=1;
            return 2;
        }
        
        //camera at child                       21,12,22
        if(left == 2||right == 2){  
            return 1;
        }

        //No camera to cover current node but might get covered by above    11
        return 0;
    }
}