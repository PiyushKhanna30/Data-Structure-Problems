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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nodes;
        if(!head)return nodes;
        ListNode *t = head;
        while(t)
        {
            nodes.push_back(t->val);
            t=t->next;
        }
        int n = nodes.size();
        vector<int>result(n,0);
        stack<int>st;
        result[n-1]=0;
        st.push(nodes[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nodes[i])
                st.pop();
            if(st.empty())
                result[i]=0;
            else
                result[i]=st.top();
            st.push(nodes[i]);
        }
        return result;
    }
};