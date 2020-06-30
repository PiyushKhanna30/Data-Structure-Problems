// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node * rev(Node *root)
{
    Node *nex=NULL,*cur=root,*prev=NULL;
    while(cur)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    return prev;
}
void reorderList(Node* head) {
    // Your code here
    Node *sp=head;
    Node *fp=head;
    //FINDING MID OF LL
    while(fp!=NULL && fp->next!=NULL)
    {
        sp=sp->next;
        fp=fp->next->next;
    }
    Node *head2=sp->next;
    sp->next=NULL;
    sp=head;
    //REVERSIN HALF LL
    head2=rev(head2);
    //COMBINING LL's
    Node *temp=new Node(0);
    while(sp || head2)
    {
        if(sp)
        {
            temp->next=sp;
            temp=temp->next;
            sp=sp->next;
        }
        if(head2)
        {
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
    }
    head=temp->next;
}
