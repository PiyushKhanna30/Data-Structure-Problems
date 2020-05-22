/**
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL


Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].
**/
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* t=head;
        if(t==NULL||t->next==NULL||t->next->next==NULL)
        {
            return head;
        }
        ListNode* odd_head=head;
        ListNode* even_head=head->next;
        ListNode* t1=odd_head;
        ListNode* t2=even_head;
        while(t2!=NULL && t2->next!=NULL)
        {
            t1->next=t2->next;
            t1=t1->next;
            t2->next=t1->next;
            t2=t2->next;
        }
        t1->next=even_head;
        return odd_head;
    }
};
