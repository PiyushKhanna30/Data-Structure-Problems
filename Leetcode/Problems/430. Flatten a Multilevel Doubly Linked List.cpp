/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *t;
    void flattenHelp(Node *head)
    {
        if(!head)return;
        
        Node *m = t;
        t->next = new Node(head->val);
        t=t->next;
        t->prev = m;

        flattenHelp(head->child);
        flattenHelp(head->next);
        return;
    }
    Node* flatten(Node* head) {
        if(!head)return head;
        Node *res = new Node(0);
        t = res;
        flattenHelp(head);
        res=res->next;
        res->prev = NULL;
        return res;
    }
};
//Note 
// we cant here just use same nodes as we keep on updating next
// pointer so we create node a in when coming back from recursion
// step we need to go to old next node.