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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *t = new ListNode(0);
        t->next = head;
        head = t;
        unordered_map<int,ListNode*>m;
        int prefix = 0;
        while(t)
        {
            prefix+=t->val;
            m[prefix]=t;
            t=t->next;
        }
        t=head;
        prefix = 0;
        while(t)
        {
            prefix+=t->val;
            t->next = m[prefix]->next;
            t=t->next;
        }
        return head->next;
    }
};