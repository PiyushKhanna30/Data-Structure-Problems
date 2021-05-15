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
unsigned max(unsigned a,unsigned b)
{
    return (a>b)?a:b;
}
class Solution {
public:
    int width;
    unordered_map<unsigned,unsigned>um;
    int widthOfBinaryTree(TreeNode* root) {
        unsigned level=1;
        unsigned position=1;
        width=0;
        getWidth(root,level,position);
        return width;
    }
    void getWidth(TreeNode* root,unsigned level,unsigned position)
    {
        if(root==NULL)
            return;
        if(um.find(level)==um.end())
            um[level]=position;
        width=max(width,position-um[level]+1);
        getWidth(root->left,level+1,position*2);
        getWidth(root->right,level+1,position*2+1);
    }
};
/*
we know that if tree represented by [10,40,20,30,null,60,50] then it is represented by

    LEVELS      REPRESENTATION                      POSITIONS OF EACH NODE
    level=1          10                                 1
                    /  \                            /        \
    level=2        40  20                        (1*2=2)    (1*2+1=3)
                  /   /  \                       /           /       \    
    level=2     30  60   50                    (2*2=4)    (2*3=6)   (2*3+1=7)
    
    Now in begining of every level we store the left most position in map
    then we call and subtract the right most position from the same level and get the width for that level
    Note we increment by 1 as at initial position 1 1-1=0 but width =1.
    
    Steps:
    1.Create map to store leftmost position with key as level and position as key.
    2.calculate max width
    3.call on left and right and increment the level and the position of node.
    4.Repeat till root!=NULL
    
    
*/