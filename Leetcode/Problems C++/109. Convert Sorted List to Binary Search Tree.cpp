/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *findMid(ListNode* &h)
    {
        if(!h || !h->next)return h;
        
        ListNode*f=h,*s=h,*p=NULL;
        while(f && f->next)
        {
            p = s;
            s = s->next;
            f = f->next->next;
        }
        if(p)
            p->next = NULL;
        return s;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);
        ListNode *mid = findMid(head);
        TreeNode *r = new TreeNode(mid->val);
        r->left = sortedListToBST(head);
        r->right = sortedListToBST(mid->next);
        return r;
    }
};