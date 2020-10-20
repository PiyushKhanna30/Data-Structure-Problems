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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* n = new ListNode(0);
        n->next = head;
        ListNode *t=head;
        head = n;
        bool repeat = false;
        while(t)
        {
            repeat = false;
            while(t->next && t->val==t->next->val)
            {
                t=t->next;
                repeat = true;
            }
            if(!repeat)
            {
                n->next = t;
                n=n->next;
                t=t->next;
            }
            else
                t=t->next;
            
        }
        n->next = NULL;
        return head->next;
    }
};