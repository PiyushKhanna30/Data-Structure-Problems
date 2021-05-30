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
    ListNode *findMid(ListNode *h)
    {
        ListNode *s=h,*f=h;
        ListNode *prev;
        while(f && f->next)
        {
            f=f->next->next;
            prev =s;
            s=s->next;
        }
        return prev;
    }
    ListNode *reverse(ListNode* h)
    {
        ListNode*c=h,*n,*p=NULL;
        while(c)
        {
            n=c->next;
            c->next = p;
            p=c;
            c=n;
        }
        return p;
    }
    ListNode* merge(ListNode* l1,ListNode *l2)
    {
        ListNode *res=new ListNode (0),*t = res;
        while(l1 && l2)
        {
            t->next = l1;
            l1=l1->next;
            t=t->next;
            
            t->next = l2;
            l2=l2->next;
            t=t->next;
        }
        
        while(l1)
        {
            t->next = l1;
            l1=l1->next;
            t=t->next;
        }
        
        while(l2)
        {
            t->next = l2;
            l2=l2->next;
            t=t->next;
        }
        return res->next;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return ;
        
        ListNode *mid = findMid(head);
        ListNode *h2 = mid->next;
        mid->next=NULL;
        
        h2  = reverse(h2);
        
        head = merge(head,h2);
        return;
    }
};
//Approaches
// 1.Using vector: store values in it then swap values in nodes;
// 2.find mid,then reverse then merge sort