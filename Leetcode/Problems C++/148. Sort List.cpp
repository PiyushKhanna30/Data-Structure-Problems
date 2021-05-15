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
class Solution {
public:
    ListNode *mergeList(ListNode*h1,ListNode* h2)
    {
        ListNode *h = new ListNode(0);
        ListNode *t =h;
        while(h1 && h2)
        {
            if(h1->val<h2->val)
            {
                t->next = h1;
                t=t->next;
                h1=h1->next;
            }
            else
            {
                t->next = h2;
                t=t->next;
                h2=h2->next;
            }
        }
        while(h1)
        {
            t->next = h1;
            t=t->next;
            h1=h1->next;
        }
        while(h2)
        {
            t->next = h2;
            t=t->next;
            h2=h2->next;
        }
        return h->next;
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode *sp=head,*fp = head,*t=NULL;
        while(fp && fp->next)
        {
            fp=fp->next->next;
            t=sp;
            sp=sp->next;
        }
        t->next=NULL;
        return sp;
        
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode *mid = findMid(head);
        
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        head = mergeList(left,right);
        return head;
    }
};