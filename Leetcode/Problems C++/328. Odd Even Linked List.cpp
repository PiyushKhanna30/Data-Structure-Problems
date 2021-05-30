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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *t=head;
        ListNode *o=t,*to=o;
        ListNode *e=t->next,*te=e;
        t = t->next->next;
        bool odd = true;
        while(t)
        {
            if(odd)
            {
                to->next = t;
                to=to->next;
                
            }
            else
            {
                te->next = t;
                te=te->next;
            }
            t = t->next;
            odd = !odd;
        }
        to->next = e;
        te->next = NULL;
        return o;
        
    }
};