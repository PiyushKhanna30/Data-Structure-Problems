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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode * l=lists[i];
            while(l)
            {
                pq.push(l->val);
                l=l->next;
            }
        }
        
        ListNode *head=new ListNode (0);
        ListNode *t = head;
        while(!pq.empty())
        {
            t->next = new ListNode(pq.top());
            pq.pop();
            t = t->next;
        }
        return head->next;
        
    }
    
};