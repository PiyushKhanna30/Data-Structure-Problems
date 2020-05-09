/**
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Note:
The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root,int x,int &parent,int h)
    {
        if(root==NULL)
            return 0;
        if(root->val==x)
            return h;
        parent=root->val;
        int l=height(root->left,x,parent,h+1);
        if(l)
            return l;
        parent=root->val;
        int r=height(root->right,x,parent,h+1);
        if(r)
            return r;
        return 0;

    }
    bool isCousins(TreeNode* root, int x, int y) {
        int parent1=-1;
        int h1=height(root,x,parent1,0);

        int parent2=-1;
        int h2=height(root,y,parent2,0);
        cout<<parent1<<endl;
        cout<<h1<<endl;
        cout<<parent2<<endl;
        cout<<h2<<endl;

        if(parent1!=parent2 && h1==h2)
            return true;
        return false;
    }
};
