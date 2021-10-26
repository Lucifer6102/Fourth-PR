struct node *reverse (struct node *head, int k){
	node* prev=NULL;
	node* curr=head;
	node* q;
	int counter=k;
	while(counter-- && curr!=NULL)
	{
		q=curr->next;
		curr->next=prev;	
		prev=curr;
		curr=q;
	}
	if(head!=NULL)
	 head->next=reverse(q,k);
	return prev;
}
// Time- O(n)
// Space - O(n)  //if inbuilt stack is considered
//			O(1) //If inbuilt stack is not considered