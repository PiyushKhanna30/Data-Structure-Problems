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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*>result;
        int n=0;
        ListNode *t = root;
        while(t)
        {
            t=t->next;
            n++;
        }
        int nk = n/k;
        int rk = n%k;
        t = root;
        
        while(t)
        {
            ListNode *p=NULL,*m = t;
            for(int i=1;i<=nk;i++)
            {
                p=t;
                t=t->next;
            }
            if(rk!=0)
            {
                rk--;
                p=t;
                t=t->next;
            }
            p->next = NULL;
            result.push_back(m);
        }
        while(result.size()!=k)
        {
            result.push_back(NULL);
        }
        return result;
    }
};