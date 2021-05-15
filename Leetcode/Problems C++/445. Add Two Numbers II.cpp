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
    void sum(ListNode *l1, ListNode *l2,int &carry)
    {
        if(!l1)return;
        sum(l1->next,l2->next,carry);
        int n = l1->val + l2->val + carry;
        carry = n/10;
        l1->val = n%10;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1=0,s2=0;
        ListNode* t1=l1,*t2=l2;
        while(t1)
        {
            s1+=1;
            t1=t1->next;
        }
        while(t2)
        {
            s2+=1;
            t2=t2->next;
        }
        cout<<s1<<" "<<s2;
        if(s1<s2)
        {
            while(s1<s2)
            {
                s1++;
                ListNode *t = new ListNode(0);
                t->next = l1;
                l1=t;
            }
        }
        
        else if(s2<s1)
        {
            while(s2<s1)
            {
                s2++;
                ListNode *t = new ListNode(0);
                t->next = l2;
                l2=t;
            }
        }
        
        int carry = 0;
        sum(l1,l2,carry);
        if(carry!=0)
        {
            ListNode *t = new ListNode(carry);
            t->next = l1;
            l1 = t;
        }
        return l1;
    }
};