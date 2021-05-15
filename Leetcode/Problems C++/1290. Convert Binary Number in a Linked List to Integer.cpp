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
    int getDecimalValue(ListNode* head) {
        int n = head->val;
        ListNode *t = head;
        while(t->next)
        {
            t = t->next;
            n = 2*n + t->val;
        }
        return n;
        
    }
};
//n=1
//n=2*1 + 0
//n=2*2*1+2*0+1
//n=5


// class Solution {
// public:
//     int getDecimalValue(ListNode* head) {
//         int n = head->val;
//         ListNode *t =head;
//         while(t->next)
//         {
//             t=t->next;
//             n = n<<1;
//             n = n|t->val;
//         }
//         return n;
//     }
// };
// //BIT WISE
// //eg 101
// //set n = head->val
// // n=1
// //n=n<<1|0 == 2
// //n=n<<1|1 ==5