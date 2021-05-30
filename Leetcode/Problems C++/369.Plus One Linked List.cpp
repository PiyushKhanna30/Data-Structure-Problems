int carry;

void addHelp(Node *head)

{
    
	if(!head)
        
		return;
    
	addHelp(head->next);
    
	int sum = head->data+carry;
    
	head->data = sum%10;
    
	carry = sum/10;

}

Node* addOne(Node *head) 

{
    
	// Your Code here
    
	// return head of list after adding one
    
	if(!head)
        
		return head;
    
	carry=1;
    
	addHelp(head);
    
	if(carry!=0)
    
	{
        
		Node *t=new Node(carry);
	
        t->next = head;
        
		head=t;
    
	}
    
	return head;

}