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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)return head;
        ListNode *s=new ListNode(0),*ts = s;
        ListNode *h=new ListNode(0),*th = h;
        ListNode *t = head;
        while(t)
        {
            if(t->val<x)
            {
                s->next = t;
                s=s->next;
            }
            else
            {
                h->next = t;
                h=h->next;
            }
            cout<<t->val<<" ";
            t=t->next;
        }
        s->next = th->next;
        h->next = NULL;
        return ts->next;
    }
};