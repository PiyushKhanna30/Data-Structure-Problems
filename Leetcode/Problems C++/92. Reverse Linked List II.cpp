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
    ListNode * reverse(ListNode *head)
    {
        if(!head || !head->next)return head;
        ListNode * cur =head,*prev = NULL;
        while(cur)
        {
            ListNode* n =cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n)return head;
        ListNode *mt , *nt, *prevmt, *nextnt;
        
        ListNode *t = new ListNode(0);
        t->next = head;
        head = t;
        while(t)
        {
            m--;
            n--;
            if(m==0)
            {
                mt = t->next;
                prevmt = t;
            }
            if(n==0)
            {
                nt = t->next;
                nextnt = nt->next;
                break;
            }
            t=t->next;
        }
        nt->next = NULL;
        nt = reverse(mt);
        mt->next = nextnt;
        prevmt->next = nt;
        return head->next;
    }
};

//RECURSIVE
// class Solution {
// public:
//     ListNode *mt;
//     bool stop;
//     void revHelp(ListNode* head, int m, int n)
//     {
//         if(m-1==0)
//         {
//             mt = head;
//         }
//         if(n==0)
//         {
//             return;
//         }
//         revHelp(head->next,m-1,n-1);
//         if(head->next==mt || head==mt || stop)
//         {
//             stop=true;
//             return;
//         }
//         int temp = mt->val;
//         mt->val = head->val;
//         head->val = temp;
//         mt=mt->next;
        
//     }
//     ListNode* reverseBetween(ListNode* head, int m, int n) {
//         if(!head || !head->next)return head;
//         stop = false;
//         revHelp(head,m,n);
//         return head;
//     }
// };