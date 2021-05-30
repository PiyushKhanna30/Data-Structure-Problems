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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int l=0;
        ListNode*t=head;
        ListNode*last;
        while(t)
        {
            l+=1;
            last=t;
            t=t->next;
        }
        k=k%l;
        last->next=head;
        t=head;
        for(int i=1;i<l-k;i++)
            t=t->next;
        head=t->next;
        t->next=NULL;
        return head;
    }
};