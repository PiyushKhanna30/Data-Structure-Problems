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
    ListNode* mid(ListNode *r)
    {
        ListNode* f=r,*s=r,*p;
        while(f && f->next)
        {
            f=f->next->next;
            p=s;
            s=s->next;
        }
        return p;
    }
    ListNode *rev(ListNode *r)
    {
        ListNode *p=NULL,*c=r,*n;
        while(c)
        {
            n = c->next;
            c->next = p;
            p = c;
            c=n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode * m = mid(head);
        ListNode *l1=head,*l2=m->next;
        m->next=NULL;
        
        l2 = rev(l2);
        
        while(l2 && l1)
        {
            if(l2->val != l1->val)return false;
            l2 = l2->next;
            l1 = l1->next;
        }
        return true;
    }
};