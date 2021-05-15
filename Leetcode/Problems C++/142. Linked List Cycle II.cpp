/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        
        ListNode*f = head,*s= head;
        
        bool cycle = false;
        while(f && f->next)
        {
            f = f->next->next;
            s=s->next;
            if(f==s)
            {
                cycle=true;
                break;
            }
        }
        if(!cycle)return NULL;
        
        s=head;
        if(f==s)return s;
        while(s->next!=f->next)
        {
            s=s->next;
            f=f->next;
        }
        return s->next;
    }
};