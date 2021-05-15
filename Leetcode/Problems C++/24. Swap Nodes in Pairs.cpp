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
    ListNode* swapPairs(ListNode* head) {
        ListNode *t = new ListNode(0);
        t->next = head;
        head =t;
        while(t && t->next && t->next->next)
        {
            ListNode *a = t->next;
            ListNode *b = t->next->next;
            a->next = b->next;
            b->next = a;
            t->next = b;
            t=t->next->next;
        }
        return head->next;
    }
};