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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=0,lb=0;
        ListNode *ta=headA;
        while(ta!=NULL)
        {
            la+=1;
            ta=ta->next;
        }
        ta=headA;
        ListNode *tb=headB;
        while(tb!=NULL)
        {
            lb+=1;
            tb=tb->next;
        }
        tb=headB;
        if(lb>la)
        {
            int c=lb-la;
            while(c--)
            {
                tb=tb->next;
            }
            while(ta || tb)
            {
                if(ta==tb)
                    return ta;
                ta=ta->next;
                tb=tb->next;
            }
        }
        else
        {
            int c=la-lb;
            while(c--)
            {
                ta=ta->next;
            }
            while(ta || tb)
            {
                if(ta==tb)
                    return ta;
                ta=ta->next;
                tb=tb->next;
            }
        }
        return NULL;
    }
};