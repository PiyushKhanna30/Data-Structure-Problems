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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *sp = dummy ,*fp = dummy;
        n+=1;
        while(fp && n)
        {
            fp = fp->next;
            n--;
        }
        if(n!=0)
            return head;
        while(fp)
        {
            fp = fp->next;
            sp = sp->next;
        }
        
        sp->next = sp->next->next;
        return dummy->next;         //not head as -1 -> 1->2 so if n = 2
    }
};