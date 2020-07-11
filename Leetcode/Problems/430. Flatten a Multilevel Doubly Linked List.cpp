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
    void help(Node *h) 
    {
        if(h!=NULL) 
        {
           t->next=new Node(h->val) ;
           Node *q=t;
           t=t->next;
           t->prev=q;
           help(h->child) ;
           help(h->next) ;
        }
    }
    Node* flatten(Node* head) {
        Node *root=new Node(5) ;
        t=root;
        help(head);
        root=root->next;
        if(root) 
            root->prev=NULL;
        return root;
    }
};