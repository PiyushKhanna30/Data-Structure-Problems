/*Complete the function
Node is as follows:

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

*/
void check(Node *root,Node *&first,Node *&mid,Node *&last,Node **prev)
{
    if(root!=NULL)
    {//JUST LIKE INORDER EXPLORE LEFT SUB TREE
        check(root->left,first,mid,last,prev);
        if(*prev!=NULL && root->data<(*prev)->data)
        {
            if(first==NULL)
            {
                first=*prev;
                mid=root;
            }
            else
            {
                last=root;
            }
        }
        *prev=root;
        check(root->right,first,mid,last,prev);
    }
}
struct Node *correctBST( struct Node* root )
{
    // add code here
    Node *head=root;
    Node *first=NULL;Node *mid=NULL;Node *last=NULL;Node *prev=NULL;
    check(head,first,mid,last,&prev);
    if(first && last)
    {
        int t=first->data;
        first->data=last->data;
        last->data=t;
    }
    else if(first && mid)
    {
        int t=first->data;
        first->data=mid->data;
        mid->data=t;
    }
    return root;
}
