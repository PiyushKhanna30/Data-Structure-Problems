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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode *sp=head;
        ListNode *fp=head;
        ListNode *sp_prev=NULL;
        ////FINDING THE MID oF LINKED LIST
        while(fp!=NULL && fp->next!=NULL)
        {
            sp_prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        
        if(fp!=NULL)                ////[1,2,5,2,1] here fp=1 and [1,2,2,1]  here fp=NULL
        {
            sp=sp->next;
        }
        sp_prev->next=NULL;
        
        ////REVERSING THE HALF oF LINKED LIST
        
        ListNode *cur=sp;
        ListNode *nex=NULL;
        ListNode *prev=NULL;
        while(cur)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        cur=prev;
        
        ListNode* h1=head;
        while(cur && h1)
        {
            if(cur->val==h1->val)
            {
                cur=cur->next;
                h1=h1->next;
            }
            else 
            {
                return false;
            }
        }
        if(cur==NULL && h1==NULL)
            return true;
        return false;
        
    }
};