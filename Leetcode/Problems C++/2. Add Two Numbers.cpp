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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* t=ans;
        int carry=0;
        int x=0;
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                x=l1->val+l2->val;
                x=x+carry;
                carry=0;
                int temp=x%10;
                carry=x/10;
                t->next=new ListNode(temp);
                t=t->next;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
            {
                x=l1->val;
                x=x+carry;
                carry=0;
                int temp=x%10;
                carry=x/10;
                t->next=new ListNode(temp);
                t=t->next;
                l1=l1->next;
            }
            else
            {
                x=l2->val;
                x=x+carry;
                carry=0;
                int temp=x%10;
                carry=x/10;
                t->next=new ListNode(temp);
                t=t->next;
                l2=l2->next;
            }
        }
        if(carry!=0)
            t->next=new ListNode(carry);
        return ans->next;
    }
};