/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node *newHead = new Node(0),*th=newHead;
        Node *t= head;    
        while(t)
        {
            Node *tmp = new Node(t->val);
            tmp->next = t->next;
            tmp->random = t->random;
            
            t->next = tmp;
            t=tmp->next;
        }
        t=head->next;
        while(t)
        {
            if(t->random)
            {
                t->random = t->random->next;
            }
            if(t->next)
                t=t->next->next;
            else
                t=t->next;
        }
        
        t=head;
        while(t)
        {
            th->next = t->next;
            th = th->next;
            t->next = th->next;
            t=t->next;
        }
        return newHead->next;
        
    }
};